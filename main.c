#include <malloc.h>
#include <stdio.h>

typdef struct Evaluations;

typedef struct {
  char name[40];
  char foodCategory[40];
  Evaluations rate[20];
} Restaurant;

typedef struct {
  Restaurant *restaurant;
  float rate;
  char comment[120];
} Evaluation;

typedef struct {
  int count;
  // For each evaluation I'll allocate its size
  //  and add it to the array;
  Evaluation* ratings[];
} Evaluations;

void listRestaurants(Restaurant restaurants[]);
void printRestaurant(Restaurant *restaurant);
void signInRestaurant();
void rateRestaurant(Restaurant *restaurant);

// SHOW MENUS
void showWelcome() {
  printf("Wolcome to FoodSquare - The IMDB of Restaurants ");
}

int menuSelectionHandler() {
  int option;
  printf("Select menu number:");
  scanf("%d", &option);

  return option;
}

void showMainMenu(Restaurant restaurants[]) {
  printf("1 - Show Restaurants");
  printf("2 - Sign in your Restaurant");
  printf("3 - Top 5 restaurants");
  switch (menuSelectionHandler()) {
  case 1:
    listRestaurants(restaurants);
    break;
  case 2:
    signInRestaurant();
    break;
  default:
    showMainMenu();
    break;
  }
}

int showRestaurantMenu() {
  printf("1 - Rate this Restaurant");
  printf("2 - Back to Restaurants list");

  switch (menuSelectionHandler()) {
  case 1:
    rateRestaurant();
    break;
  case 2:
    listRestaurants();
    break;
  default:
    showMainMenu();
    break;
  }
}

// END MENUS

// RESTAURANT FEATURES
// List all
void listRestaurants(Restaurant restaurants[]) {
  for (int i = 0; i < sizeof(*restaurants); i++) {
    printRestaurant(&restaurants[i]);
  }
}

void printRestaurant(Restaurant *restaurant) {
  printf("Name: %s", restaurant->name);
  printf("Type of food: %s", restaurant->foodCategory);
  
  printf("Users rating: %f", &restaurant->rate);
}

void restaurantRate() {
  
}

void signInRestaurant(Restaurant *restaurants[]) {
  Restaurant *restaurant = (Restaurant *)malloc(sizeof(Restaurant));
  printf("Restaurant name:");
  scanf("%s", restaurant->name);
  printf("Type of Food:");
  scanf("%s", restaurant->name);
}

void rateRestaurant(Restaurant *restaurant) {
  Evaluation *evaluation = (Evaluation *)malloc(sizeof(Evaluation));
  printf("What do you think about this Restaurant:");
  scanf("%s", evaluation->comment);

  printf("Rate this Restaurant:");
  scanf("%f", &evaluation->rate);
}

int main() {

  showWelcome();
  showMainMenu();

  return 0;
}
