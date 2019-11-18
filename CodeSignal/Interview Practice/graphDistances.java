import java.util.*;

class Pair<K, V> {
    K a;
    V b;
    
    public Pair(K key, V value) {
        this.a = key;
        this.b = value;
    }
    
    public K getKey() {
        return a;
    }
    
    public V getValue() {
        return b;
    }
}

class graphDistances {

    public static int[] graphDistances(int[][] g, int s) {
        int nodes = g.length,
            maxDist = 31;

        ArrayList<ArrayList< Pair<Integer, Integer>>> edges = new ArrayList<ArrayList<Pair<Integer, Integer>>>(nodes);
        int[] dist = new int[nodes];

        for (int i = 0; i < g.length; ++i) {
            ArrayList<Pair<Integer, Integer>> edge = new ArrayList< Pair<Integer, Integer>>();

            for (int j = 0; j < g[i].length; ++j) {
                int w = g[i][j];

                if (w != -1) {
                    edge.add(new Pair<Integer, Integer>(w, j));
                }
            }

            edges.add(edge);
            dist[i] = maxDist;
        }

        TreeSet<Pair<Integer, Integer>> S = new TreeSet<Pair<Integer, Integer>>(new Comparator<Pair<Integer, Integer>>() {
            @Override
            public int compare(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
                if (a.getKey() == b.getKey()) {
                    return a.getValue() - b.getValue();
                }

                return a.getKey() - b.getKey();
            }
        });

        S.add(new Pair<Integer, Integer>(0, s));
        dist[s] = 0;

        while (S.size() > 0) {
            Pair<Integer, Integer> current = S.pollFirst();
            int currentWeight = current.getKey(),
                currentNode = current.getValue();

            for (int i = 0; i < edges.get(currentNode).size();  ++i) {
                Pair<Integer, Integer> neighbor = edges.get(currentNode).get(i);
                int neighborWeight = currentWeight + neighbor.getKey(),
                    neighborNode = neighbor.getValue();

                if (neighborWeight < dist[neighborNode]) {
                    dist[neighborNode] = neighborWeight;
                    S.add(new Pair<Integer, Integer> (neighborWeight, neighborNode));
                }
            }
        }

        return dist;
    }

    public static void main(String[] args) {
        int[][] g = {{-1, 3, 2},
                     {2, -1, 0},
                     {-1, 0, -1}};

        System.out.println(Arrays.toString(graphDistances(g, 0)));
    }
}