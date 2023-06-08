#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Node {
    public:
    char label[80];
    Node(char *newlabel) {//constructor
        strcpy(label, newlabel);
    }
};
class Edge {
    public:
    Node* first;
    Node* second;
    int weight;
    Edge(Node* newfirst, Node* newsecond, int newweight) {
        first = newfirst;
        second = newsecond;
        weight = newweight;
    }
};

void printAdjacency(vector<vector<int> > table) {
    cout << endl;
    for (int a = 0; a < table.size(); ++a) {
            for (int b= 0; b < table[0].size(); ++b) {
                cout << table[a][b] << "\t";
            }
            cout << endl;
        }
}
int main() {

	v.push_back({1, 0, 1});
    bool cont = true;
    char input[80];
    vector<Node*>nodeList;//vector of all nodes
    vector<Edge*>edgeList;//vector of all edges
    vector<vector<int> > table; //2D vector for adjacency table

    while (cont == true) {
        cout << "Add vertex, add edge, remove vertex, remove edge, find shortest path, or print adjacency? (av, ae, rv, re, path, print)?: ";
        cin >> input;
        cin.ignore();
        if (strcmp(input, "av") == 0) {//add vertex
            char label[80];
            cout << "Vertex label to add: ";
            cin >> label;
            cin.ignore();
            Node* newnode = new Node(label);//create new node
            nodeList.push_back(newnode);//add node to listNodes vector
            table.push_back({0, 0});//add new vector to table
            for (int i = 0; i < table.size()-1; ++i) {
                table[i].push_back(0);
            }
            for (int i = 0; i < table.size(); ++i) {
                table[table.size()-1].push_back(0);
            }
            printAdjacency(table);
        }
        else if (strcmp(input, "ae") == 0) {//add edge
            char label1[80];
            char label2[80];
            Node* node1;
            Node* node2;
            int weight;
            cout << "First node label: ";
            cin >> label1;
            cin.ignore();
            cout << "Second node label: ";
            cin >> label2;
            cin.ignore();
            if (strcmp(label1, label2)!=0) {//if they're not the same
                for (int i = 0; i < nodeList.size(); ++i) {//find node that matches the label
                    if (strcmp(nodeList[i]->label, label1) == 0) {
                        node1 = nodeList[i];
                    }
                    if (strcmp(nodeList[i]->label, label2) == 0) {
                        node2 = nodeList[i];
                    }
                }
                cout << "Weight: ";
                cin >> weight;
                Edge* newedge = new Edge(node1, node2, weight);
                edgeList.push_back(newedge);
            }
            else {
                cout << "Make sure they are different" << endl;
            }
        }
        else if (strcmp(input, "rv")==0) {//remove vertex
            char label[80];
            cout << "Vertex label to remove: ";
            cin >> label;
            cin.ignore();
        }
        else if (strcmp(input, "re") == 0) {//remove edge
            char label1[80];
            char label2[80];
            cout << "First Vertex label ";
            cin >> label1;
            cin.ignore();
            cout << "Second Vertex label ";
            cin >> label2;
            cin.ignore();


        }
        else if (strcmp(input, "path") == 0) {//find shortest path
            
        }
        else if (strcmp(input, "print") == 0) {//print adjacency table
            printAdjacency(table);
        }
        else if (strcmp(input, "quit") == 0) {//quit
            cont = false;
        }
        else {
            cout << "Invalid input." << endl;
        }
    }
}