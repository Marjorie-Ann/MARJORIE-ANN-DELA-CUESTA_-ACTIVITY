#include <iostream>
using namespace std;

string karaoke_queue[100];

int front = 0;
int rear = -1;
int max_queue = 10;

struct SongWithPriority {
    string title;
    int priority;
};

bool isFull() {
    if (rear == max_queue - 1) {
        return true;
    }
    return false;
}

bool isEmpty() {
    if (rear == -1) {
        return true;
    }
    return false;
}

string enqueue(string song) {
    if (isFull()) {
        return "The queue is full. Try again later";
    }
    karaoke_queue[++rear] = song;
    return "A new song has been added in the queue";
}

string dequeue() {
    if (isEmpty()) {
        return "There is no song in the queue. Try adding first";
    }
    string song = karaoke_queue[front];

    for (int i = 1; i <= rear; i++) {
        karaoke_queue[i - 1] = karaoke_queue[i];
    }
    rear--;
    return song;
}

int main() {
    SongWithPriority priority_queue[10]; 
    int priority_count = 0;

    auto enqueue_with_priority = [&](string title, int priority) {
        if (priority_count < max_queue) {
            priority_queue[priority_count++] = {title, priority};
           
            for (int i = 1; i < priority_count; ++i) {
                SongWithPriority key = priority_queue[i];
                int j = i - 1;
                while (j >= 0 && priority_queue[j].priority > key.priority) {
                    priority_queue[j + 1] = priority_queue[j];
                    j--;
                }
                priority_queue[j + 1] = key;
            }
            cout << "Added '" << title << "' with priority " << priority << endl;
        } else {
            cout << "Priority queue is full." << endl;
        }
    };

    auto dequeue_priority = [&]() {
        if (priority_count > 0) {
            string highest_priority_song = priority_queue[priority_count - 1].title;
            cout << "Dequeued (highest priority): " << highest_priority_song << endl;
            priority_count--;
            return highest_priority_song;
        } else {
            cout << "Priority queue is empty." << endl;
            return string("");
        }
    };

    cout << "Simulating priority queue operations:" << endl;

    enqueue_with_priority("Bulaklak", 3);
    enqueue_with_priority("Wonderful Tonight", 2);
    enqueue_with_priority("Zombie", 4);

    cout << "Current priority queue (highest priority last):" << endl;
    for (int i = 0; i < priority_count; ++i) {
        cout << priority_queue[i].title << " (Priority: " << priority_queue[i].priority << ")" << endl;
    }

    dequeue_priority();
    dequeue_priority();

    cout << "Remaining priority queue (highest priority last):" << endl;
    for (int i = 0; i < priority_count; ++i) {
        cout << priority_queue[i].title << " (Priority: " << priority_queue[i].priority << ")" << endl;
    }

    enqueue_with_priority("Selos", 5);
    enqueue_with_priority("Stairway to Heaven", 1);
    enqueue_with_priority("Hotel California", 3);
    enqueue_with_priority("Imagine", 4);
    enqueue_with_priority("Musika", 2);
    enqueue_with_priority("Breathless", 5);
    enqueue_with_priority("Billie Jean", 3);
    enqueue_with_priority("Sayang na Sayang", 1);

    cout << "Priority queue is now full or near full (highest priority last)." << endl;
    for (int i = 0; i < priority_count; ++i) {
        cout << priority_queue[i].title << " (Priority: " << priority_queue[i].priority << ")" << endl;
    }

    dequeue_priority();

    enqueue_with_priority("Frauline", 4);

    cout << "Priority queue after dequeue and enqueue (highest priority last):" << endl;
    for (int i = 0; i < priority_count; ++i) {
        cout << priority_queue[i].title << " (Priority: " << priority_queue[i].priority << ")" << endl;
    }

    return 0;
}