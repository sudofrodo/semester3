

#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

// ─── Global State ────────────────────────────────────────────────────────────
stack<int> plateStack;   // Main stack holding plate weights
int  score       = 0;    // Player score (+2 push, -1 pop)
int  pushAttempts = 0;   // Total push attempts made
int  platesStacked = 0;  // Total plates currently in the stack
// ─────────────────────────────────────────────────────────────────────────────

/*
 * displayStack()
 *   Prints every plate in the stack from top to bottom.
 *   Uses a temporary stack to iterate without destroying the original.
 */
void displayStack() {
    if (plateStack.empty()) {
        cout << "  [Stack is empty]" << endl;
        return;
    }

    stack<int> temp = plateStack;
    vector<int> plates;

    while (!temp.empty()) {
        plates.push_back(temp.top());
        temp.pop();
    }

    cout << "  Stack (TOP --> BOTTOM): ";
    for (size_t i = 0; i < plates.size(); i++) {
        cout << "[" << plates[i] << "]";
        if (i + 1 < plates.size()) cout << " -> ";
    }
    cout << endl;
    cout << "  Number of plates in stack: " << plateStack.size() << endl;
}

/*
 * peekPlate()
 *   Displays the top plate weight without removing it.
 *   Returns -1 if the stack is empty.
 */
int peekPlate() {
    if (plateStack.empty()) {
        cout << "  Stack is empty. No top plate to view." << endl;
        return -1;
    }
    cout << "  Top plate weight: " << plateStack.top() << endl;
    return plateStack.top();
}

/*
 * pushPlate(weight)
 *   Attempts to place a new plate on top of the stack.
 *   Returns false if the stack collapses (game over condition).
 *
 *   Rules enforced:
 *     - New plate weight must be <= top plate weight.
 *     - Placing a heavier plate triggers a collapse and ends the game.
 */
bool pushPlate(int weight) {
    pushAttempts++;

    // Collapse condition: new plate is heavier than the current top
    if (!plateStack.empty() && weight > plateStack.top()) {
        cout << "\n  *** COLLAPSE! ***" << endl;
        cout << "  Plate [" << weight << "] is heavier than top plate ["
             << plateStack.top() << "]. The stack has COLLAPSED!" << endl;
        return false;  // Signal game over
    }

    plateStack.push(weight);
    platesStacked++;
    score += 2;
    cout << "  Plate [" << weight << "] added successfully.  (+2 points)" << endl;
    return true;
}

/*
 * popPlate()
 *   Removes the top plate from the stack.
 *   Deducts 1 point per removal.
 */
void popPlate() {
    if (plateStack.empty()) {
        cout << "  Stack is empty. No plate to remove." << endl;
        return;
    }
    int removed = plateStack.top();
    plateStack.pop();
    platesStacked--;
    score -= 1;
    cout << "  Plate [" << removed << "] removed from stack.  (-1 point)" << endl;
}

/*
 * displayEndGame(won)
 *   Shows the final game summary: win/lose status, score, remaining plates.
 */
void displayEndGame(bool won) {
    cout << "\n========================================" << endl;
    cout << "           GAME OVER" << endl;
    cout << "========================================" << endl;

    if (won) {
        cout << "  Result  : ** YOU WIN! **" << endl;
        cout << "  5 plates successfully balanced!" << endl;
    } else {
        cout << "  Result  : You LOSE." << endl;
    }

    cout << "  Final Score      : " << score << " points" << endl;
    cout << "  Push Attempts    : " << pushAttempts << " / 10" << endl;
    cout << "  Plates in Stack  : " << plateStack.size() << endl;

    if (!plateStack.empty()) {
        cout << endl;
        displayStack();
    }
    cout << "========================================" << endl;
}

// ─── Main Game Loop ──────────────────────────────────────────────────────────
int main() {
    cout << "========================================" << endl;
    cout << "   Plate Stack Balancing Game" << endl;
    cout << "   CSC211 - Data Structures" << endl;
    cout << "========================================" << endl;
    cout << "Rules:" << endl;
    cout << "  - Push: add a plate (weight must be <= top plate)" << endl;
    cout << "  - Pop : remove the top plate" << endl;
    cout << "  - Peek: view top plate without removing" << endl;
    cout << "  - View: display the full stack" << endl;
    cout << "  - Stack 5 plates within 10 push attempts to WIN" << endl;
    cout << "  - Placing a heavier plate COLLAPSES the stack" << endl;
    cout << "  - Scoring: +2 per push, -1 per pop" << endl;
    cout << "  Commands: push <weight>  |  pop  |  peek  |  view  |  quit" << endl;
    cout << "========================================\n" << endl;

    string command;
    bool gameOver = false;
    bool won      = false;

    while (!gameOver) {
        cout << "[ Attempts: " << pushAttempts << "/10 | Plates: "
             << plateStack.size() << " | Score: " << score << " ]" << endl;
        cout << "Command: ";
        cin >> command;

        if (command == "push") {
            int weight;
            if (!(cin >> weight)) {
                cout << "  Invalid weight. Please enter an integer." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            bool ok = pushPlate(weight);

            if (!ok) {
                // Stack collapsed → instant loss
                gameOver = true;
            } else {
                displayStack();

                // Win check: 5 plates on the stack
                if ((int)plateStack.size() >= 5) {
                    won      = true;
                    gameOver = true;
                }
                // Attempt limit check
                else if (pushAttempts >= 10) {
                    cout << "\n  10 push attempts used. You failed to stack 5 plates." << endl;
                    gameOver = true;
                }
            }

        } else if (command == "pop") {
            popPlate();
            displayStack();

        } else if (command == "peek") {
            peekPlate();

        } else if (command == "view") {
            displayStack();

        } else if (command == "quit") {
            cout << "  Quitting game..." << endl;
            gameOver = true;

        } else {
            cout << "  Unknown command. Use: push <weight> | pop | peek | view | quit" << endl;
        }

        cout << endl;
    }

    displayEndGame(won);
    return 0;
}
