#include <stdio.h>

#define ROWS 5
#define COLS 10

// User-Defined Function Declarations
void initializeAuditorium(int seats[ROWS][COLS]);
void displayAuditorium(int seats[ROWS][COLS]);
void bookSeat(int seats[ROWS][COLS]);
void cancelSeat(int seats[ROWS][COLS]);
void findConsecutiveSeats(int seats[ROWS][COLS]);
void generateReport(int seats[ROWS][COLS]);

int main() {
    int seats[ROWS][COLS];
    int choice;

    // Initialize all seats to available (0)
    initializeAuditorium(seats);

    do {
        printf("\n=================================\n");
        printf("    SEATSMART - AUDITORIUM SYSTEM\n");
        printf("=================================\n");
        printf("1. Display Seating Chart\n");
        printf("2. Book a Seat\n");
        printf("3. Cancel Reservation\n");
        printf("4. Find Consecutive Seats for Group\n");
        printf("5. Generate Occupancy Report\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAuditorium(seats);
                break;
            case 2:
                bookSeat(seats);
                break;
            case 3:
                cancelSeat(seats);
                break;
            case 4:
                findConsecutiveSeats(seats);
                break;
            case 5:
                generateReport(seats);
                break;
            case 6:
                printf("Exiting SEATSMART. Have a great event!\n");
                break;
            default:
                printf("Invalid choice! Please choose between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

// 1. Initialize all seats to 0 (Available)
void initializeAuditorium(int seats[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            seats[i][j] = 0;
        }
    }
}

// 2. Display the grid of seats visually
void displayAuditorium(int seats[ROWS][COLS]) {
    printf("\n--- Auditorium Seating Chart ---\n");
    printf("     ");
    for (int j = 0; j < COLS; j++) {
        printf("C%-2d ", j + 1);
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("R%-2d  ", i + 1);
        for (int j = 0; j < COLS; j++) {
            if (seats[i][j] == 0) {
                printf("[ ]  "); // Available
            } else {
                printf("[X]  "); // Booked
            }
        }
        printf("\n");
    }
    printf("Legend: [ ] = Available | [X] = Booked\n");
}

// 3. Book a specific seat
void bookSeat(int seats[ROWS][COLS]) {
    int r, c;
    printf("Enter row (1 to %d) and column (1 to %d) to book: ", ROWS, COLS);
    scanf("%d %d", &r, &c);

    if (r < 1 || r > ROWS || c < 1 || c > COLS) {
        printf("Error: Invalid seat coordinates! Out of bounds.\n");
        return;
    }

    if (seats[r - 1][c - 1] == 1) {
        printf("Seat R%d-C%d is already booked! Please choose another.\n", r, c);
    } else {
        seats[r - 1][c - 1] = 1;
        printf("Success! Seat R%d-C%d has been successfully reserved.\n", r, c);
    }
}

// 4. Cancel an existing reservation
void cancelSeat(int seats[ROWS][COLS]) {
    int r, c;
    printf("Enter row (1 to %d) and column (1 to %d) to cancel: ", ROWS, COLS);
    scanf("%d %d", &r, &c);

    if (r < 1 || r > ROWS || c < 1 || c > COLS) {
        printf("Error: Invalid seat coordinates!\n");
        return;
    }

    if (seats[r - 1][c - 1] == 0) {
        printf("Seat R%d-C%d is already vacant.\n", r, c);
    } else {
        seats[r - 1][c - 1] = 0;
        printf("Success! Reservation for R%d-C%d has been cancelled.\n", r, c);
    }
}

// 5. Find consecutive available seats in a single row for groups
void findConsecutiveSeats(int seats[ROWS][COLS]) {
    int groupSize;
    printf("Enter number of consecutive seats needed: ");
    scanf("%d", &groupSize);

    if (groupSize < 1 || groupSize > COLS) {
        printf("Error: Invalid group size.\n");
        return;
    }

    int found = 0;
    for (int i = 0; i < ROWS; i++) {
        int consecutiveCount = 0;
        for (int j = 0; j < COLS; j++) {
            if (seats[i][j] == 0) {
                consecutiveCount++;
                if (consecutiveCount == groupSize) {
                    int startCol = j - groupSize + 2;
                    int endCol = j + 1;
                    printf("Found! %d consecutive seats available in Row %d from Column %d to %d.\n", 
                           groupSize, i + 1, startCol, endCol);
                    found = 1;
                    break;
                }
            } else {
                consecutiveCount = 0;
            }
        }
        if (found) break;
    }

    if (!found) {
        printf("Sorry, no %d consecutive seats are available together in any single row.\n", groupSize);
    }
}

// 6. Generate an audit/occupancy report
void generateReport(int seats[ROWS][COLS]) {
    int totalSeats = ROWS * COLS;
    int bookedSeats = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (seats[i][j] == 1) {
                bookedSeats++;
            }
        }
    }

    int availableSeats = totalSeats - bookedSeats;
    float occupancyRate = ((float)bookedSeats / totalSeats) * 100.0;

    printf("\n=================================\n");
    printf("   AUDITORIUM OCCUPANCY REPORT   \n");
    printf("=================================\n");
    printf("Total Seats      : %d\n", totalSeats);
    printf("Booked Seats     : %d\n", bookedSeats);
    printf("Available Seats  : %d\n", availableSeats);
  printf("Occupancy Rate   : %.2f%%\n", occupancyRate);
  printf("=================================\n");
}
