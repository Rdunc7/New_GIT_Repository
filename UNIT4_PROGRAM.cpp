#include <iostream>
#include <iomanip>

using namespace std;

// Constants for discounts
const double DISCOUNT_10_ROOMS = 0.10;
const double DISCOUNT_20_ROOMS = 0.20;
const double DISCOUNT_30_ROOMS = 0.30;
const double EXTRA_DISCOUNT_3_DAYS = 0.05;

int main() {
    double roomCost, salesTax;
    int numRooms, numDays;
    double discount = 0.0;

    // Prompt user for input
    cout << "Enter the cost of renting one room: $";
    cin >> roomCost;
    cout << "Enter the number of rooms booked: ";
    cin >> numRooms;
    cout << "Enter the number of days the rooms are booked: ";
    cin >> numDays;
    cout << "Enter the sales tax (as a percent): ";
    cin >> salesTax;

    // Determine discount based on number of rooms booked
    if (numRooms >= 30) {
        discount = DISCOUNT_30_ROOMS;
    } else if (numRooms >= 20) {
        discount = DISCOUNT_20_ROOMS;
    } else if (numRooms >= 10) {
        discount = DISCOUNT_10_ROOMS;
    }

    // Apply extra discount if rooms are booked for at least 3 days
    if (numDays >= 3) {
        discount += EXTRA_DISCOUNT_3_DAYS;
    }

    // Calculate total cost
    double discountedRoomCost = roomCost * (1 - discount);
    double totalRoomCost = discountedRoomCost * numRooms * numDays;
    double totalTax = totalRoomCost * (salesTax / 100);
    double totalBillingAmount = totalRoomCost + totalTax;

    // Output results
    cout << fixed << setprecision(2);
    cout << "Cost of renting one room: $" << roomCost << endl;
    cout << "Discount on each room: " << discount * 100 << "%" << endl;
    cout << "Number of rooms booked: " << numRooms << endl;
    cout << "Number of days the rooms are booked: " << numDays << endl;
    cout << "Total cost of the rooms: $" << totalRoomCost << endl;
    cout << "Sales tax: " << salesTax << "%" << endl;
    cout << "Total billing amount: $" << totalBillingAmount << endl;

    return 0;
}
