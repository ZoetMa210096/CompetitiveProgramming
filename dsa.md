# DSA Cheatsheat

All Data structures and algorithms I have used throughout my competitive programming journey.

## Overview

1. C++ Basics

2. Searching and Sorting

3. Strings

4. Math

5. Trees

6. Graphs

## 1. C++ Basics

### 1.1. Structs

Structs are a way to group related variables or different data types.

The following code creates an unnamed struct and 2 struct variables:

```cpp
struct {
	string name;
	int age;
} person1, person2;

// accessing and modifying person1 and person2
person1.age = 42;
cout << person1.age;

person2.name = "theo";
cout << person2.name;
```

Named structs allow creating multiple variables during runtime.

```cpp
struct person {
	string name;
	int age;
};

// creating new person variable
person p1;

p1.name = "cleo";
p1.age = 35;
cout << p1.name << " " << p1.age;
```

A custom comperator can be added to structs as well.

```cpp
struct person {
	string name;
	int age;
	// sorts primarly by age, if age is equal then by name
	bool operator<(const person &p) {
		if(age == p.age) return name < p.name;
		else return age < p.age;
	}
};
```
## 2. Searching and Sorting

All Algorithms related to searching and sorting data.
### 2.1. Searching

#### 2.1.1. Binary Search

Binary search is used to find out whether a given number or data exists in a sorted array or not faster than a brute force search.

**Time Complexity:** $O(log(n))$

**Code:**

```cpp
bool binsearch(vector<int>& arr, int target) {
    int l = 0, r = arr.size() - 1;
    while(l <= r) {
        int mid = l + (r - l) / 2; // used to avoid overflow
        if(arr[mid] == target) {
            return true; // found target
        }
        else if(arr[mid] < target) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return false; // didn't find target in array
}
```

### 2.1.2. Conditional Binary Search

A conditional binary search is used when you want to know the position of the last `false` element in an array or the first `true` element in an array. Note that the array has to be "sorted" such that there is a point $k$ in the array where $cond(arr[i]) = a$ for $i <= k$ and $cond(arr[j]) = !a$ for $j > k$.

**Time Complexity:** $O(log(n))$

**Code:**

```cpp
// finds the position of the first elem in the array
// for which the condition returns false
int cond_binsearch(vector<int>& arr) {
    int l = 0, r = arr.size() - 1;
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(arr[mid] < 5) { // custom condition
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    return l; // returning r works too, since l = r at the end
}
```

## 2.2. Sorting

TBA

## 3. Strings

### 3.1. LPS (Longest Prefix Suffix)

Used to determine the longest prefix that is also a suffix for a string $s$ in the range $[0,i]$ for $i<n$.

**Time Complexity:** $O(n)$

**Code:**

```cpp
// finds the longest prefix that is also a
// suffix for every substring [0,i]
vector<int> lps(string substr) {
    int n = substr.length();
    vector<int> pref(n + 1);
    int i = 0, j = -1;
    pref[i] = j; // there exists no lps for s[0]
    while(i < n) {
        while(j >= 0 && w[j] != w[i]) // while no match is found
            j = pref[j];
        pref[++i] = ++j;
    }
    return pref;
}
```

### 3.2. KMP (Knuth-Morris-Pratt-Algorithm)

### 3.3. Trie

Tries are tree structures which store strings efficiently. They allow generating all sub-strings of a string in $O(n²)$ time using a suffix tree.
#### 3.3.1. Node Struct

**Code:**
``` cpp
struct Node {

	// links to other trie nodes
    Node *links[26];
    // true if end of string
    bool flag = false;

	// checks if a node already exists
    bool containsKey(char c) { return (links[c-'a'] != NULL); }
    // adds a node
    void put(char c, Node* node) { links[c-'a']=node; }
    Node* get(char c) { return links[c-'a']; }
    void setEnd() { flag=true; }
    bool isEnd() { return flag; }
};
```

#### 3.3.2. Trie Insert

Inserts a given string $s$ into the trie.

**Time Complexity:** $O(s)$

**Code:**
``` cpp
void insert(string word) {
	// dummy node starting from root
	Node* node = root;
	for(int i = 0; i < word.length(); ++i) {
		// if node doesn't exist, generate node
		if(!node->containsKey(word[i])) node->put(word[i], new Node());
		// move to next node
		node=node->get(word[i]);
	}
	// mark end of string
	node->setEnd();
}
```

#### 3.3.3 Trie Search

Checks if a string $s$ exists in the trie.

**Time Complexity:** $O(s)$

**Code:**
``` cpp
bool search(string word) {
	// dummy node starting from root
	Node* node = root;
	for(int i = 0; i < word.length(); ++i) {
		// if next node doesn't exist, trie doesn't contain string
		if(!node->containsKey(word[i])) return false;
		// move to next node
		node=node->get(word[i]);
	}
	// check if string ends here
	return node->isEnd();
}
```

#### 3.3.4. Trie StartsWith

Checks if a string prefix $p$ exists in a trie.

**Time Complexity:** $O(p)$

**Code:**
```cpp
bool startsWith(string pref) {
	// dummy node starting from root
	Node* node = root;
	for(int i = 0; i < pref.length(); ++i) {
		// if next node doesn't exist, trie doesn't contain string
		if(!node->containsKey(pref[i])) return false;
		// move to next node
		node=node->get(pref[i]);
	}
	// only difference to search: always return true
	// even if string doesn't end here
	return true;
}
```
## 4. Math

### 4.1. Sieve of Eratosthenes

The Sieve of Eratosthenes is used to detect prime numbers up to a range $n$ quickly. It is often called at the beginning of a program to write all prime numbers into a vector. Note: $n$ should only be around ~10 million max.

**Time Complexity:** $O(n\cdot log(log(n)))$

**Code:**
``` cpp
vector<int> primes;
const int n = 1'000'000;

void sieve() {
    vector<bool> p(n+1,true);
    for(ll i = 2; i*i <= n; ++i)
        if(p[i])
            for(ll j = i*i; j <= n; j+=i)
                p[j]=false;
    for(int i = 2; i <= n; ++i)
        if(p[i]) primes.push_back(i);
}
```

### 4.2. Prime Factorization

An efficient prime factorization algorithm is used to find prime factors of a number quickly. A prerequisite of prime factorization is generating all prime factors in the needed range.

**Time Complexity:** $O(\sqrt{n})$

**Code:**
```cpp
vector<int> pFac(int x) {
	vector<int> _pFac;
    for (ll prime : primes) {
        if (prime*prime>x||x==1) break;
        while (x%prime==0) {
            x/=prime;
            _pFac.push_back(prime);
        }
    }
    if (x>1) _pFac.push_back(x);
    return _pFac;
}
```

### 4.3. GCD (Greatest Common Divisor)

Finds the GCD of two numbers $a$ and $b$ quickly, where $a >= b$.

**Time Complexity:** $log(min(a,b))$

**Code:**
```cpp
int gcd(int a, int b) {
	if(!b) return a;
	return gcd(b,a%b);
}
```
## 5. Trees

### 5.1. Fenwick Tree (Binary Indexed Tree)

A fenwick tree is used for finding out the sum of the values of an array interval in logarithmic time. A prefix sum array will allow you to return the sum in $O(1)$ time, however all update operations take $O(n)$ time. A fenwick tree finds a perfect balance by allowing both update and query operations to take $O(log(n))$ time.

#### 5.1.1. Build

Builds the Fenwick tree. To use this, repeatedly call the update function with all values in the input array.

**Time Complexity:** $O(n\cdot log(n))$

#### 5.1.2. Update

Update the value of any array. The fenwick tree will adept in logarithmic time.

**Time Complexity:** $O(log(n))$

**Code:**

```cpp
void update(int idx, ll val) {
    while(idx < N) { // N is size of input arr
        fen[idx]+=val; // add val to current index
        idx+=idx&(~idx+1); // move on to next important index
    }
}
```

#### 5.1.3. Query

Query the sum in range $[0;i]$.

**Time Complexity:** $O(log(n))$

**Code:**

```cpp
ll query(int idx) {
    ll s = 0;
    while(idx) {
        s+=fen[idx]; // add current range to sum
        idx&=idx-1; // move on to next range
    }
    return s;
} 
```

#### 5.1.4. Range Query

Query the sum in range $[l;r]$.

**Time Complexity:** $O(log(n))$

**Code:**

```cpp
ll rangeQuery(int l, int r) {
    return query(r) - query(l-1);
}
```

### 5.2. Segment Tree

A segment tree is a data structure (binary tree) used to store intervals. It allows logarithmic query time, which is much faster than linear time. The examples will cover a sum segment tree, however segment trees also allow storing by other criteria (max, min,... ). The height of the segment tree will be $log(n)$.

#### 5.2.1. Build

Base function that builds the segment tree. A segment tree can take up to 4 times the space of the input array.

**Time Complexity:** $O(n)$

**Code:**

```cpp
// call with idx=0, low=0, high=n-1
void build(int idx, int low, int high) {
    if(low==high) { // interval only consists of 1 element
        seg[idx]=arr[high];
        return;
    }
    int mid = (low+high)/2;
    build(idx*2+1, low, mid); // build left node
    build(idx*2+2, mid+1, high); // build right node
    seg[idx]=seg[idx*2+1]+seg[idx*2+2]; 
}
```

#### 5.2.2. Query

With a query function you can find the wanted result in logarithmic time.

**Time Complexity:** $O(log(n))$

**Code:**

```cpp
// call with idx=0, low=0, high=n-1, ql=left border, qr=right border
ll query(int idx, int low, int high, int ql, int qr) {
    // query completely covers seg interval
    if(low>=ql && high<=qr) return seg[idx];
    // seg interval is outside query
    // returning 0, this doesn't affect the result
    else if(high<ql || low>qr) return 0; 

    int mid = (low+high)/2;
    return query(idx*2+1, low, mid, ql, qr) + 
           query(idx*2+2, mid+1, high, ql, qr);
}
```

#### 5.2.3. Update

Update the value of any element in the array. The segment tree updates in logarithmic time.

**Time Complexity:** $O(log(n))$

**Code:**

```cpp
// call with idx=0, low=0, high=n-1, uidx=update index, uval=update value
void update(int idx, int low, int high, int uidx, int uval) {
    if(low==high) {
        seg[idx]=uval;
        return;
    }
    int mid = (low+high)/2;
    // update index lies on the left side of segment tree
    if(uidx<=mid) update(idx*2+1, low, mid, uidx, uval);
    // update index lies on the right side of segment tree
    else update(idx*2+2, mid+1, high, uidx, uval);
    // update current node
    seg[idx]=seg[idx*2+1]+seg[idx*2+2];
}
```

### 5.3. Lazy Segment Tree

If you want to update an interval in a segment tree by some value e.g. $a[i] := a[i] + 3$ for $i=[l;r]$ lazy propagation is needed (Otherwise it will take $n\cdot log(n)$ time which is too slow if called multiple times). For this you will need to create a replica of the segment tree where every node is initialized to zero (Lazy Segment Tree).

#### 5.3.1. Range Update

Updates an interval in a segment tree by a given value.

**Time Complexity:** $O(log(n))$

**Code:**

```cpp
// call with idx=0, low=0, high=n-1,
// ul=left border, ur=right border, uval=update value
void rangeUpdate(int idx, int low, int high, int ul, int ur, int uval) {
    // see if there are any lazy updates pending
    if(lazy[idx]) {
        seg[idx] += lazy[idx]*(high-low+1);
        // update lazy seg tree
        if(low!=high) {
            lazy[idx*2+1] += lazy[idx];
            lazy[idx*2+2] += lazy[idx];
        }
        lazy[idx] = 0;
    }
    // lies outside range, return
    if(high<ul || low>ur) return;
    // completely inside range
    if(low>=ul && high<=ur) {
        seg[idx] += uval*(high-low+1);
        if(low!=high) {
            lazy[idx*2+1] += uval;
            lazy[idx*2+2] += uval;
        }
        return;
    }

    int mid = (low+high)/2;
    rangeUpdate(idx*2+1, low, mid, ul, ur, uval);
    rangeUpdate(idx*2+2, mid+1, high, ul, ur, uval);
    seg[idx] = seg[idx*2+1] + seg[idx*2+2];
}
```

#### 5.3.2 Lazy Query

Allows for correct querying in a lazy segment tree (Additional lazy check at start).

**Time Complexity:** $O(log(n))$

**Code:**

```cpp
// call with idx=0, low=0, high=n-1, ql=left border, qr=right border
ll lazyQuery(int idx, int low, int high, int ql, int qr) {
    // see if there are any lazy updates pending
    if(lazy[idx]!=0) {
        seg[idx] += lazy[idx]*(high-low+1);
        // update lazy seg tree
        if(low!=high) {
            lazy[idx*2+1] += lazy[idx];
            lazy[idx*2+2] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    // query completely covers seg interval
    if(low>=ql && high<=qr) return seg[idx];
    // seg interval is outside query
    // returning 0, this doesn't affect the result
    else if(high<ql || low>qr) return 0; 

    int mid = (low+high)/2;
    return lazyQuery(idx*2+1, low, mid, ql, qr) + 
           lazyQuery(idx*2+2, mid+1, high, ql, qr);
}
```

## 6. Graphs
### 6.1. Basic Traversal 

#### 6.1.1. DFS (Depth-First-Search)

DFS is used for traversing graphs and trees. The algorithm typicly starts at the root node and then explores a path until it isn't able to go any further.

**Time Complexity:** $O(|V|+|E|)$ where $|V|$ is the number of verticies/nodes and $|E|$ is the amount of edges.

**Code:** 

```cpp
void dfs(map<int, vector<int>>& adjList, set<int>& vis, int cur) {
    vis.insert(cur);
    cout << cur << "\n";
    for(int adj : adjList[cur]) // visit all neighbors of node
        if(!vis.count(adj))
            dfs(adjList, vis, adj);
}
```

#### 6.1.2. BFS (Breadth-First-Search)

BFS (like DFS) is used for traversing graphs and trees. The difference is that BFS explores every path at the same time instead of picking a path and then fully exploring it.

**Time Complexity:** $O(|V|+|E|)$ where $|V|$ is the number of verticies/nodes and $|E|$ is the amount of edges.

**Code:**

```cpp
void bfs(map<int, vector<int>>& adjList, int root) {
    queue<int> q;
    q.push(root);
    set<int> vis = {root};
    while(!q.empty()) {
        int top = q.front();
        cout << top << "\n";
        vis.insert(top);
        for(int adj : adjList[top]) // visit all neighbors of node
            if(!vis.count(adj))
                q.push(adj);
    }
}
```

### 6.2. Min Cost Algorithms

All graph algorithms related to finding the shortest paths between indices in a weighted graph.
#### 6.2.1. Floyd Warshall Algorithm (All Pairs Shortest Path)

The Floyd Warshall Algorithm finds the shortest paths between all node pairs in a graph. It maintains an adjacency matrix of the graph and updating it as it finds shorter paths using intermediate nodes. The algorithm works for both positive and negative edge weights, but does not work for graphs with negative cycles (sum of the edges in a cycle is negative).

**Time Complexity:** $O(|V|³)$

**Code:**

``` cpp
// setting up distance adj matrix
for(int i = 0; i < n; ++i) {
	for(int j = 0; j < n; ++j) {
		if(i==j) dist[i][j]=0; // no edge from node to same node
		else if(adj[i][j]) dist[i][j]=adj[i][j]; // edge from A to B
		else dist[i][j]=INFINITY; // no edge from A to B
	}
}

// finding the shortest paths
for(int k = 0; k < n; ++k) {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			// dist[i][j] is shortest path from i to j
			dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
		}
	}
}
```

### 6.3. Strong Connectivity

A directed graph is called strongly connected if there is a path from any node to all
other nodes in the graph. Furthermore, a directed graph can always be divided into strongly connected components (SCC). There are multiple algorithms related to finding the strongly connected components of a graph.
#### 6.3.1. Kosaraju's Algorithm

**Usage:** Kosaraju's Algorithm is used to efficiently discover all SCC's in a graph. It utilizes 2 Depth first searches: The first one creates a list of all nodes processed in order. Then, all the edges are reversed. Finally, the second DFS goes in order of the list of the first DFS, finding all SCC's in the graph.

**Time Complexity:** $O(|V|+|E|)$ 

**Code:**

``` cpp
// first dfs to find the order of nodes
void dfsOrder(unordered_map<int, vector<int>>& adj, vector<bool>& vis, int node, stack<int>& order) {
    vis[node]=true;
    for(int n : adj[node])
        if(!vis[n])
            dfsOrder(adj, vis, n, order);
    order.push(node);
}

// regular dfs to find sccs
void dfs(unordered_map<int, vector<int>>& adjT, vector<bool>& vis, int node) {
    vis[node]=true;
    for(int n : adjT[node])
        if(!vis[n])
            dfs(adjT, vis, n);
}

int main() {

	// call dfsOrder
	for(int i = 0; i < n; ++i) {
        if(!vis[i])
            dfsOrder(adj, vis, i, order);
    }

	// reverse all edges an store the resulting graph in adjT
	// also, set vis[i] to false so they can be visited in the next dfs
    unordered_map<int, vector<int>> adjT(n);
    for(int i = 0; i < n; ++i) {
        vis[i]=false;
        for(int j : adj[i])
            adjT[j].push_back(i);
    }

    int scc = 0; // keeps track of the amount of sccs
    while(!order.empty()) { // go through in reverse order (stack)
        int node = order.top();
        order.pop();
        if(!vis[node]) {
            ++scc;
            dfs(adjT, vis, node); // discovers one scc
        }
    }
    
}
```

