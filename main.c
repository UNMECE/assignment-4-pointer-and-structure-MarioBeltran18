#include "item.h"

/*This code will first take a command line input to search for the sku number
and after, will call the remaining functions and display thier result on screen*/

void add_item(Item *item_list, double price, const char *sku, const char *category, const char *name, int index) {
	//Setting price = price passed from function
	item_list[index].price = price;
	//allocate memory for sku number
	item_list[index].sku = malloc(sizeof(sku) + 1);
	strcpy(item_list[index].sku, sku);
	//allocate memory for category
	item_list[index].category = malloc(sizeof(category) + 1);
	strcpy(item_list[index].category, category);
	//allocate memory for name
	item_list[index].name = malloc(sizeof(name) + 1);
	strcpy(item_list[index].name, name);
}

//This function will free memory that was allocated from the add_item function
void free_items(Item *item_list, int size) {
	for (int i=0; i<size; i++) {
		free(item_list[i].sku);     //freeing the members of the stucture for each item
		free(item_list[i].name);
		free(item_list[i].category);
	}
}

double average_price(Item *item_list, int size) {
	//create a variable to save all of the sums in
	double sum;

	for (int i=0; i<size; i++) {
		sum += item_list[i].price;
	}
	double avarage = sum/size;

	return printf("The avarage prices of your items is as follows: %lf", avarage);
}
void print_items(Item *item_list, int size) {
	printf("Current list of items:\n\n");
	//create a for loop using the size as the index
	for (int i=0; i<size; i++) {
		printf("item name: = %s\n", item_list[i].name);
		printf("sku number: = %s\n", item_list[i].sku);
		printf("category: = %s\n", item_list[i].category);
		printf("price: = %.6f\n\n\n", item_list[i].price);
	}

}


int main(int argc, char *argv[])
{
	//Declaring itemPtr
	Item *itemPtr;

	//Using add_item function 5 times for 5 items
	add_item(itemPtr, 9.2, "12345", "Cooking Oil", "Vegtible Oil", 0);
	add_item(itemPtr, 5.0, "11234", "Snack", "Potato Chips", 1);
	add_item(itemPtr, 7.8, "11123", "Grains", "Bag of Rice", 2);
	add_item(itemPtr, 4.3, "11112", "Dairy", "Milk", 3);
	add_item(itemPtr, 2.9, "11111", "Candy", "Chocolate Bar", 4);

    //Using command line argumets for a search using the while loop
	char *search = argv[1];
	int ct = 0;

	while (ct < 5 && strcmp(itemPtr[ct].sku, search) != 0) {
		ct++;
	}
	if (ct < 5) {
		printf("\n\n");
		printf("\n\nItem found:\n");
		printf("name: %s\n", itemPtr[ct].name);
		printf("item price: %.6f\n", itemPtr[ct].price);
		printf("sku number: %s\n", itemPtr[ct].sku);
		printf("item category: %s\n", itemPtr[ct].category);

	} else {
		printf("Item not found :(");
	}

    //Using the rest of the functions after a searching to print out values 
	print_items(itemPtr, 5);
	average_price(itemPtr,5);
	free_items(itemPtr, 5);
	return 0;
}
