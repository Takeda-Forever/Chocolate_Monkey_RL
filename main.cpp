#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

// Learning parameters
const double alpha = 0.1;    // learning rate
const double gamma = 0.9;    // discount factor
const int max_state = 3;     // chocolate pieces left: 3, 2, 1, 0

// Actions: 0 - do nothing, 1 - eat 1 piece of chocolate
const int actions_count = 2;

// Q-table: Q[state][action]
double Q[max_state + 1][actions_count] = {0};

// Choose action with epsilon-greedy strategy
int chooseAction(int state, double epsilon = 0.1) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1);
    if (dis(gen) < epsilon) {
        // Exploration: random action
        uniform_int_distribution<> dis_action(0, actions_count - 1);
        return dis_action(gen);
    } else {
        // Exploitation: best action based on Q-values
        return (Q[state][0] > Q[state][1]) ? 0 : 1;
    }
}

// Reward function
double getReward(int state) {
    // If no chocolate left, full reward (satisfaction)
    if (state == 0) return 10.0;
    return 0.0;
}

// State transition function
int getNextState(int state, int action) {
    if (action == 1 && state > 0) {
        return state - 1; // ate 1 piece
    }
    return state; // no change if action = 0 or no chocolate left
}

int main() {
    int episodes = 1000; // number of training episodes

    for (int episode = 0; episode < episodes; ++episode) {
        int state = max_state; // start with full chocolate (3 pieces)

        while (state > 0) {
            int action = chooseAction(state);

            int nextState = getNextState(state, action);
            double reward = getReward(nextState);

            // Q-learning update rule
            double maxQNext = max(Q[nextState][0], Q[nextState][1]);
            Q[state][action] = Q[state][action] + alpha * (reward + gamma * maxQNext - Q[state][action]);

            state = nextState;
        }
    }

    // Output Q-table after training
    cout << "Q-table after training:" << endl;
    for (int s = max_state; s >= 0; --s) {
        cout << "State (chocolate left): " << s << "/3 -> ";
        cout << "Do nothing: " << Q[s][0] << ", Eat: " << Q[s][1] << endl;
    }

    return 0;
}
