#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);
    
    cout << "========================================" << endl;
    cout << "  LATIHAN 14.3 - GRAPH TRAVERSAL" << endl;
    cout << "========================================\n" << endl;
    
    // Latihan 1: Membuat graph sesuai Gambar 14-14
    cout << "Latihan 1: Membuat Graph Tidak Berarah\n" << endl;
    cout << "Menambahkan node A, B, C, D, E, F, G, H..." << endl;
    
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');
    
    cout << "Menghubungkan node-node sesuai Gambar 14-14..." << endl;
    
    // Koneksi sesuai Gambar 14-14
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'C');
    ConnectNode(G, 'B', 'D');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'C', 'G');
    ConnectNode(G, 'D', 'H');
    ConnectNode(G, 'E', 'H');
    ConnectNode(G, 'F', 'H');
    ConnectNode(G, 'G', 'H');
    
    PrintInfoGraph(G);
    
    // Latihan 2: Prosedur PrintDFS
    cout << "\n========================================" << endl;
    cout << "  Latihan 2: DEPTH FIRST SEARCH (DFS)" << endl;
    cout << "========================================" << endl;
    PrintDFS(G, FindNode(G, 'A'));
    
    // Latihan 3: Prosedur PrintBFS  
    cout << "\n========================================" << endl;
    cout << "  Latihan 3: BREADTH FIRST SEARCH (BFS)" << endl;
    cout << "========================================" << endl;
    PrintBFS(G, FindNode(G, 'A'));
    
    // Testing dari node lain
    cout << "\n--- Testing DFS dari node B ---" << endl;
    PrintDFS(G, FindNode(G, 'B'));
    
    cout << "\n--- Testing BFS dari node C ---" << endl;
    PrintBFS(G, FindNode(G, 'C'));
    
    cout << "\n========================================" << endl;
    cout << "  PROGRAM SELESAI" << endl;
    cout << "========================================" << endl;
    system("pause");
    return 0;
}
