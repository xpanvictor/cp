pub struct GraphEdge(usize, usize, usize);

pub struct GraphEdgeList {
    pub repr: Vec<GraphEdge>,
}

impl GraphEdgeList {
    pub fn new(data: Vec<GraphEdge>) -> Self {
        GraphEdgeList { repr: data }
    }

    pub fn add_egde(&mut self, a: usize, b: usize, weight: usize) {
        self.repr.push(GraphEdge(a, b, weight));
    }

    pub fn bellman_ford(&self) -> Vec<usize> {
        let mut distances = vec![usize::MAX; self.repr.len()];
        distances
    }
}

#[cfg(test)]
mod tests {
    use super::*;
}
