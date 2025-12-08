use std::collections::VecDeque;

struct Graph {
    pub repr: Vec<Vec<usize>>, // adjacency list
}

impl Graph {
    fn new(size: usize) -> Self {
        Graph {
            repr: vec![Vec::new(); size],
        }
    }

    fn new_data(data: Vec<Vec<usize>>) -> Self {
        Graph { repr: data }
    }

    fn add_edge(&mut self, u: usize, v: usize) {
        self.repr[u].push(v);
        self.repr[v].push(u); // undirected
    }

    fn dfs<F>(&self, u: usize, visited: &mut Vec<bool>, visit: &mut F)
    where
        F: FnMut(usize),
    {
        if visited[u] {
            return;
        };
        visit(u);
        visited[u] = true;
        for &v in &self.repr[u] {
            self.dfs(v, visited, visit);
        }
    }

    fn bfs<F>(&self, visit: &mut F) -> Vec<usize>
    where
        F: FnMut(usize),
    {
        let mut queue: VecDeque<usize> = VecDeque::new();
        queue.push_back(0);
        let mut visited = vec![false; self.repr.len()];
        let mut distances = vec![0; self.repr.len()];
        while let Some(u) = queue.pop_front() {
            if visited[u] {
                continue;
            }
            visit(u);
            visited[u] = true;
            for &v in &self.repr[u] {
                if !visited[v] {
                    queue.push_back(v);
                    distances[v] = distances[u] + 1;
                }
            }
        }
        distances
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_dfs() {
        let mut g = Graph::new(6);
        g.add_edge(0, 1);
        g.add_edge(0, 3);
        g.add_edge(1, 2);
        g.add_edge(1, 4);
        g.add_edge(2, 4);
        // node 5 is disconnected
        g.add_edge(5, 5); // self-loop to ensure node 5 exists

        let mut total = 0;
        let mut visit = |_| {
            total += 1;
        };
        g.dfs(1, &mut vec![false; 6], &mut visit);
        assert_eq!(
            total, 5,
            "DFS should visit all 5 connected nodes starting from node 0"
        );
    }

    #[test]
    fn test_bfs() {
        let mut g = Graph::new(6);
        g.add_edge(0, 1);
        g.add_edge(0, 3);
        g.add_edge(1, 2);
        g.add_edge(1, 4);
        g.add_edge(2, 5);
        g.add_edge(4, 5);

        let exp_node_heights = [0, 1, 2, 1, 2, 3];
        let mut visit = |_: usize| {};
        let distances = g.bfs(&mut visit);
        println!("Dfs distances: {:?}", distances);
        assert_eq!(
            distances, exp_node_heights,
            "BFS should compute correct node heights from the starting node"
        );
    }
}
