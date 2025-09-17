class FoodRatings {
    private Map<String, Integer> foodRating;
    private Map<String, String> foodCuisine;
    private Map<String, TreeSet<String>> cuisineFoods;
    
    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        foodRating = new HashMap<>();
        foodCuisine = new HashMap<>();
        cuisineFoods = new HashMap<>();

        for(int i=0; i<foods.length;i++){
            foodRating.put(foods[i], ratings[i]);
            foodCuisine.put(foods[i], cuisines[i]);

            cuisineFoods.putIfAbsent(cuisines[i], new TreeSet<>(
                (f1,f2) -> {
                    int r1=foodRating.get(f1);
                    int r2=foodRating.get(f2);
                    if(r1!=r2)
                    return r2-r1;
                    return f1.compareTo(f2);

                }
            ));
            cuisineFoods.get(cuisines[i]).add(foods[i]);
        }

    }
    
    public void changeRating(String food, int newRating) {
         String cuisine = foodCuisine.get(food);
        TreeSet<String> set = cuisineFoods.get(cuisine);

        set.remove(food);
        foodRating.put(food, newRating);
        set.add(food);   
    }
    
    public String highestRated(String cuisine) {
         return cuisineFoods.get(cuisine).first(); 
    }
}