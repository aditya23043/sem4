<style>
* {
	font-family: "JetBrains Mono NL";
}
</style>

# USEFUL LINKS FOR DEVLOPMENT
- https://youtu.be/09_LlHjoEiY (youtube video for graph theory)
- https://github.com/TianyiShi2001/Algorithms/ (repo in rust for almost all algos)
- https://github.com/williamfiset/algorithms (almost all algos in java)

# MID Semester Preparation for Algorithm Design & Analysis

## Depth First Search
- Graph Traversal
- Time Complexity = O(V+E)

### Algo
```pseudocode
n = number of nodes in the graph
g = adjacency list of the graph
visited = [false, false, ... false] // size n

DFS(node){

	if(visited[node]){
		return
	}
	
	visited[node] = true;
	
	for (neighbour in g[node]){
		if(!visited[neighbour])
			DFS(neighbour);
	}
}

start = 0;
DFS(start);
```


### Connected Components
- Count the number of Connected Components in a Graph
```pseudocode
n = number of nodes in the graph
g = adjacency list of the graph
visited = [false, false, ... false] // size n
count = 0
components = [0, 0, ..., 0] // size n

find_connected_components(){
	for(i <- 0 : n){
		if(!visited[n]){
			count++;
			DFS(i);
		}
	}
	return (count, num_components);
}

DFS(node){
	visited[node] = true;
	num_components[node] = count;
	for(next : g[node]){
		if(!visited[next]){
			DFS(next);
		}
	}
}
```

### Other Applications: DFS
- Compute a graph's MST
- Detect and find cycles in a graph
- Check for bipartiteness
- Find SCCs
- Topologically sort the nodes of a graph
- Find bridges
- Solve mazes

## BFS
- Time Complexity = O(V+E)
- Very useful for finding shortest path on unweighted graphs
- Utilizes a queue

### Algo
```pseudocode
n = num of nodes in the graph
g = adjacency list of the graph

BFS(s, e){
	prev = solve(s);
	return reconstruct_path(s, e, prev);
}

solve(s){
	q = queue;
	visited = [false, false, ..., false] // size n
	prev = [null, null, ..., null] // size n

	q.enqueue(s);
	visited[s] = true;

	while(!q.isEmpty()){
		node = q.dequeue();
		neighbours = g.get(node);
		
		for(next : neighbours){
			if(!visited[next]){
				q.enqueue(next);
				visited[next] = true;
				prev[next] = node;
			}
		}
	}
	return prev;
}

reconstruct_path(start, end, prev){
	path = [];
	for(i = e; i != NULL; i = prev[i]){
		path.add(i);
	}
	path.reverse();
	if(path[0] == s){
		return path;
	}
	return [];
}
```

## Dijkstra's Algorithm
- Single Source Shortest Path Algorithm
- Time Complexity: O(E * log(V))
- Gives the shortest path from the starting node to all the other nodes in the graph
- Constraint: Non negative edge weight

## MST
- All nodes must be connected
- Time Complexity: O(E * log(V))
