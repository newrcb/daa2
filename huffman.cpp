#include <iostream>
#include <cstring>
using namespace std;

// Node structure for Huffman Tree
struct Node {
    char character;
    int frequency;
    Node* left;
    Node* right;

    Node(char c, int f) : character(c), frequency(f), left(nullptr), right(nullptr) {}
};

// MinHeap structure
struct MinHeap {
    Node** array;
    int size;
    int capacity;

    MinHeap(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        array = new Node*[capacity];
    }

    ~MinHeap() {
        delete[] array;
    }
};

// Function to create a new node
Node* createNode(char character, int frequency) {
    return new Node(character, frequency);
}

// Swap two nodes
void swapNodes(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify the MinHeap
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency) {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency) {
        smallest = right;
    }

    if (smallest != idx) {
        swapNodes(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Extract the minimum node from MinHeap
Node* extractMin(MinHeap* minHeap) {
    Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}

// Insert a node into the MinHeap
void insertMinHeap(MinHeap* minHeap, Node* node) {
    minHeap->size++;
    int i = minHeap->size - 1;

    while (i && node->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

// Build the MinHeap
MinHeap* buildMinHeap(char characters[], int frequencies[], int size) {
    MinHeap* minHeap = new MinHeap(size);

    for (int i = 0; i < size; i++) {
        minHeap->array[i] = createNode(characters[i], frequencies[i]);
    }

    minHeap->size = size;

    for (int i = (minHeap->size - 2) / 2; i >= 0; i--) {
        minHeapify(minHeap, i);
    }

    return minHeap;
}

// Build the Huffman Tree
Node* buildHuffmanTree(char characters[], int frequencies[], int size) {
    Node *left, *right, *top;
    MinHeap* minHeap = buildMinHeap(characters, frequencies, size);

    while (minHeap->size > 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = createNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

// Print the Huffman Codes
void printHuffmanCodes(Node* root, char* code, int top) {
    if (root->left) {
        code[top] = '0';
        printHuffmanCodes(root->left, code, top + 1);
    }

    if (root->right) {
        code[top] = '1';
        printHuffmanCodes(root->right, code, top + 1);
    }

    if (!root->left && !root->right) {
        code[top] = '\0';
        cout << root->character << ": " << code << endl;
    }
}

// Main function
int main() {
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;

    char* characters = new char[n];
    int* frequencies = new int[n];

    cout << "Enter character and frequency pairs:\n";
    for (int i = 0; i < n; i++) {
        cout << "Character " << i + 1 << ": ";
        cin >> characters[i];
        cout << "Frequency " << i + 1 << ": ";
        cin >> frequencies[i];
    }

    Node* root = buildHuffmanTree(characters, frequencies, n);

    char code[100];
    cout << "Huffman Codes:\n";
    printHuffmanCodes(root, code, 0);

    // Clean up
    delete[] characters;
    delete[] frequencies;

    return 0;
}
