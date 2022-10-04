#include <cmath>
#include "iostream"

using namespace std;

// All questions listed
void ask_question();

// Func for every case
void do_thing_for_case_1();
void do_thing_for_case_2();
void do_thing_for_case_3();
void do_thing_for_case_4();
void do_thing_for_case_5();
void do_thing_for_case_6();
void do_thing_for_case_7();
void do_thing_for_case_8();

// Calculate values
int calculate_number_of_cards();
int calculate_number_of_sweets();
int calculate_number_of_tables();
int calculate_number_of_coke();
int calculate_number_of_water();
int calculate_total_cost_of_cards(int card_amount);
int calculate_total_cost_of_coke(int coke_amount);
int calculate_total_cost_of_water(int water_amount);

// PP = People per
int const PP_COKE_CASE = 6;
int const PP_WATER_CASE = 2;
int const PP_TABLE = 6;
double const SWEETS_PP = 1.2;
int const PP_CARDS = 2;
int const PRICE_WATER = 20;
int const PRICE_COKE = 30;
int const PRICE_CARDS = 200;

int guests = 0;
int choice;

int number_of_cards = 0;
int number_of_sweets = 0;
int number_of_tables = 0;
int number_of_coke = 0;
int number_of_water = 0;

int main() {
    cout << "\n\tThe Wedding Planning assistant is pleased to be at your service.";
    cout << "\n\nWhat services do you require? " << endl;

    while (true)
    {
        // Prints number of guests if it's set.
        if (guests != 0)
        {
            cout << "\n\tYou are planning on " << guests << " guests..." << endl;
        }

        // Prints the list of options, and waits for user input.
        ask_question();

        // Writes a fail message based on the input
        if (choice > 8 || choice < 1)
        {
            cout << "\t- Please enter a valid number and try again - " << endl;
            continue;
        }

        // Writes a fail message if the guest amount has not been set if choice is not 1 or 8
        else if (choice != 1 && choice != 8 && guests == 0)
        {
            cout << "\t- Warning, the amount of guests has not been set, please try again -" << endl;
            continue;
        }

        switch (choice) {

            // Set number of guests
            case 1:
                do_thing_for_case_1();
                break;

            // Determine number of invitation cards and sweets
            case 2:
                do_thing_for_case_2();
                break;

            // Determine number of tables
            case 3:
                do_thing_for_case_3();
                break;

            // Determine number of drinks to order
            case 4:
                do_thing_for_case_4();
                break;

            // Check cost of invitation cards
            case 5:
                do_thing_for_case_5();
                break;

            // Check cost of drinks
            case 6:
                do_thing_for_case_6();
                break;

            // Display all information
            case 7:
                do_thing_for_case_7();
                break;

            // Write quit message
            case 8:
                do_thing_for_case_8();
                return 0;

            // You dun goofed
            default:
                cout << "\n\t- Please enter a valid number and try again -" << endl;
                break;
        }
    }
}

void ask_question()
{
    cout << "\n1. Enter the number of guests";
    cout << "\n2. Determine the number of invitation cards and sweets";
    cout << "\n3. Determine the number of tables needed";
    cout << "\n4. Determine drinks order";
    cout << "\n5. Cost of invitation cards";
    cout << "\n6. Cost of drinks";
    cout << "\n7. Display all information";
    cout << "\n8. Quit" << endl;

    cout << "\nSelect an option from the ones listed above: ";

    // Will not work with string input
    cin >> choice;
    cout << endl;
}

// Calculations
int calculate_number_of_cards()
{
    return ceil(static_cast<double>(guests) / PP_CARDS);
}

int calculate_number_of_sweets()
{
    return ceil(static_cast<double>(guests) * SWEETS_PP);
}

int calculate_number_of_tables()
{
    return ceil(static_cast<double>(guests) / PP_TABLE);
}

int calculate_number_of_coke()
{
    return floor(static_cast<double>(guests) / PP_COKE_CASE);
}

int calculate_number_of_water()
{
    return ceil(static_cast<double>(guests) / PP_WATER_CASE);
}

int calculate_total_cost_of_cards(int card_amount)
{
    return card_amount * PRICE_CARDS;
}

int calculate_total_cost_of_coke(int coke_amount)
{
    return coke_amount * PRICE_COKE;
}

int calculate_total_cost_of_water(int water_amount)
{
    return water_amount * PRICE_WATER;
}

// Case functions
void do_thing_for_case_1()
{
    cout << "Enter the amount of guests you are planning for your wedding: ";
    cin >> guests;
}

void do_thing_for_case_2()
{
    number_of_cards = calculate_number_of_cards();
    number_of_sweets = calculate_number_of_sweets();
    cout << "You will need " << number_of_cards << " invitation cards, and " << number_of_sweets << " sweets in total." << endl;
}

void do_thing_for_case_3()
{
    number_of_tables = calculate_number_of_tables();
    cout << "You will need " << number_of_tables << " tables in total." << endl;
}

void do_thing_for_case_4()
{
    number_of_coke = calculate_number_of_coke();
    number_of_water = calculate_number_of_water();
    cout << "You will need " << number_of_coke << " cases of Coke and " << number_of_water << " cases of water." << endl;
}

void do_thing_for_case_5()
{
    // If the user has not determined number of cards
    if (number_of_cards == 0)
    {
        cout << "   - Total amount of cards has not yet been determined. Please determine the amount of cards needed, before proceeding -";
    }
    else
    {
        int card_amount = calculate_number_of_cards();
        int cost_of_cards = calculate_total_cost_of_cards(card_amount);
        cout << "The total cost of cards will be " << cost_of_cards << " NOK." << endl;
    }
}

void do_thing_for_case_6()
{
    // If the user has not determined number of coke or water
    if (number_of_coke == 0 || number_of_water == 0)
    {
        cout << "   - Total amount of coke and water has not yet been determined. Please determine the amount needed, before proceeding -";
    }
    else
    {
        int coke_cost = calculate_total_cost_of_coke(number_of_coke);
        int water_cost = calculate_total_cost_of_water(number_of_water);
        cout << "The cost of coke will be " << coke_cost << " NOK, and the cost of water will be " << water_cost << " NOK.";
        cout << "\nThe total cost of drinks will be " << coke_cost + water_cost << " NOK." << endl;
    }
}

void do_thing_for_case_7()
{
    // Will post all information even if cost has not been determined
    int card_cost = calculate_total_cost_of_cards(number_of_cards);
    int coke_cost = calculate_total_cost_of_coke(number_of_coke);
    int water_cost = calculate_total_cost_of_water(number_of_water);

    cout << "Total invited guests: " << guests;
    cout << "\nNeeds: " << number_of_cards << " invitation cards, " << number_of_sweets << " sweets, " << number_of_tables << " tables, " << number_of_coke << " cases of coke, " << number_of_water << " cases of water.";
    cout << "\nCost of invitation cards: " << card_cost << " NOK.";
    cout << "\nCost of drinks: " << coke_cost << " NOK for coke and " << water_cost << " NOK for water, with a total of " << coke_cost + water_cost << " NOK." << endl;
}

void do_thing_for_case_8()
{
    // Prints a quit message
    if (guests !=0)
    {
        cout << "\t- Thank you for using our services -" << endl;
    }
    else {
        cout << "\t- Shutting down -" << endl;
    }
}
