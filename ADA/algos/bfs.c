#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char value;
    struct Node *vertices;
    bool state;
};

void add_edge(struct Node from, char to) {
    // number of vertices of the "from" node
    int vertex_size = sizeof(from.vertices) / sizeof(from.vertices[0]);
    // copy them into this temp arr
    struct Node *before_vertices = malloc(vertex_size * sizeof(struct Node));
    for (int i = 0; i < vertex_size; i++) {
        before_vertices[i] = from.vertices[i];
    }
    // create a new array with size+1
    if (from.vertices != NULL) {
        free(from.vertices);
    }
    from.vertices = malloc((vertex_size + 1) * sizeof(struct Node));
    for (int i = 0; i < vertex_size; i++) {
        from.vertices[i] = before_vertices[i];
    }
    free(before_vertices);
    // add the "to" node as a vertex of the "from" node
    struct Node new_vertex = {to, NULL, false};
    from.vertices[vertex_size] = new_vertex;
}

void cleanup(struct Node node) {
    int vertex_size = sizeof(node.vertices) / sizeof(node.vertices[0]);
    if (node.vertices != NULL) {
        return;
    }
    for (int i = 0; i < vertex_size; i++) {
        cleanup(node.vertices[i]);
    }
    free(node.vertices);
}

int main(int argc, char *argv[]) {

    struct Node starting_node = {'A', NULL, false};
    add_edge(starting_node, 'B');

    // at this point i have a bunch of mem allocated on the heap in the form of
    // <Node>.vertices. How do i free them now?
    // I could use a recursive approach
    cleanup(starting_node);

    return 0;
}
