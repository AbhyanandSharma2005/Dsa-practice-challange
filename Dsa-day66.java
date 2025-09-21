import java.util.*;
class MovieRentingSystem {
    static class Pair {
        int price, shop;
        Pair(int p,int s){price=p;shop=s;}
    }
    static class Triple {
        int price, shop, movie;
        Triple(int p,int s,int m){price=p;shop=s;movie=m;}
    }
    Map<Integer, TreeSet<Pair>> movieMap;
    TreeSet<Triple> rented;
    Map<Long, Integer> priceMap;
    Comparator<Pair> pairComp = (a,b)-> a.price!=b.price ? Integer.compare(a.price,b.price) : Integer.compare(a.shop,b.shop);
    Comparator<Triple> tripleComp = (a,b)-> a.price!=b.price ? Integer.compare(a.price,b.price) : (a.shop!=b.shop?Integer.compare(a.shop,b.shop):Integer.compare(a.movie,b.movie));
    public MovieRentingSystem(int n, int[][] entries) {
        movieMap = new HashMap<>();
        rented = new TreeSet<>(tripleComp);
        priceMap = new HashMap<>();
        for(int[] e: entries){
            int shop=e[0], movie=e[1], price=e[2];
            movieMap.computeIfAbsent(movie, k->new TreeSet<>(pairComp)).add(new Pair(price,shop));
            priceMap.put(key(shop,movie), price);
        }
    }
    long key(int shop,int movie){return (((long)shop)<<32) | (movie & 0xffffffffL);}
    public List<Integer> search(int movie) {
        List<Integer> res = new ArrayList<>();
        TreeSet<Pair> set = movieMap.get(movie);
        if(set==null || set.isEmpty()) return res;
        Iterator<Pair> it = set.iterator();
        int k=0;
        while(it.hasNext() && k<5){
            res.add(it.next().shop);
            k++;
        }
        return res;
    }
    public void rent(int shop, int movie) {
        int price = priceMap.get(key(shop,movie));
        TreeSet<Pair> set = movieMap.get(movie);
        set.remove(new Pair(price,shop));
        rented.add(new Triple(price,shop,movie));
    }
    public void drop(int shop, int movie) {
        int price = priceMap.get(key(shop,movie));
        TreeSet<Pair> set = movieMap.computeIfAbsent(movie, k->new TreeSet<>(pairComp));
        set.add(new Pair(price,shop));
        rented.remove(new Triple(price,shop,movie));
    }
    public List<List<Integer>> report() {
        List<List<Integer>> res = new ArrayList<>();
        Iterator<Triple> it = rented.iterator();
        int k=0;
        while(it.hasNext() && k<5){
            Triple t = it.next();
            res.add(Arrays.asList(t.shop, t.movie));
            k++;
        }
        return res;
    }
}
