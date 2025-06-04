# 🍫 Chocolate Monkey – Q-Learning Example in C++
This project demonstrates a simple Q-Learning reinforcement learning algorithm using a fun analogy:
A monkey is in a room with a chocolate bar divided into three pieces. The goal is to learn the best way to eat all the chocolate and get the highest reward (satisfaction).

### 🧠 Idea
The monkey (agent) can:
- Eat a piece of chocolate (action = 1)
- Do nothing (action = 0)
The environment keeps track of how many pieces of chocolate remain (state = 3, 2, 1, or 0).
The monkey receives a reward only when the chocolate is completely eaten.

### 🛠️ Features
Implemented in pure C++
Simple Q-table for learning optimal actions
Uses ε-greedy strategy for exploration/exploitation
Demonstrates core concepts of reinforcement learning

### 📋 Example Output
After training, the program prints a table of learned Q-values:
vbnet
Copy
Edit
State (chocolate left): 3/3 -> Do nothing: 0.00, Eat: 4.81  
State (chocolate left): 2/3 -> Do nothing: 0.00, Eat: 6.25  
State (chocolate left): 1/3 -> Do nothing: 0.00, Eat: 8.39  
State (chocolate left): 0/3 -> Do nothing: 0.00, Eat: 0.00  
The agent learns that eating is the best action in every state.

### 📦 How to Run
Clone the repository:
bash
```
git clone https://github.com/Takeda-Forever/Chocolate_Monkey_RL.git
cd Chocolate_Monkey_RL
```
Compile and run the code:

bash
```
g++ monkey_q_learning.cpp -o monkey
./monkey
```
### 📚 Learning Concepts
State – current number of chocolate pieces
Action – what the monkey chooses to do
Reward – +10 only if chocolate is fully eaten
Q-Learning Update Rule:
lua
Copy
Edit
Q[s][a] = Q[s][a] + α * (reward + γ * max(Q[next_state]) - Q[s][a])
Parameters:
α = learning rate
γ = discount factor

### 🤖 Why This Project?
This project is intended as a minimal, intuitive introduction to reinforcement learning using C++.
It’s perfect for beginners who want to understand how agents learn from trial and error.

##### 📌 License
MIT License. Feel free to use, modify, and share.
