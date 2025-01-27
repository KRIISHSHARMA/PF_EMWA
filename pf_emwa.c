#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>

#define NUM_USERS 5         // number of users
#define NUM_SLOTS 10        // number of scheduling slots
#define S_F 0.5           // EMWA smoothing factor


void updateAverageSINR(double *avgSINR, double currentSINR);
int selectUser(double *pfMetric);

int main() {
    double sinr[NUM_USERS];          
    double avgSINR[NUM_USERS];      
    double pfMetric[NUM_USERS];    
    int slot;                        

    //random seed for SINR
    srand(time(0));
    for (int i = 0; i < NUM_USERS; i++) {
        sinr[i] = (double)(rand() % 50 + 10) / 10.0;  
        avgSINR[i] = sinr[i];                         
    }

    printf("Proportional Fair Scheduling Simulation\n");
    printf("=======================================\n");

    // for each slot
    for (slot = 0; slot < NUM_SLOTS; slot++) {
        printf("\nSlot %d:\n", slot + 1);

        // EMWA update for each user
        for (int i = 0; i < NUM_USERS; i++) {
            sinr[i] = (double)(rand() % 50 + 10) / 10.0;  
            updateAverageSINR(&avgSINR[i], sinr[i]);      
            pfMetric[i] = sinr[i] / avgSINR[i];           

           
            printf("User %d: SINR = %.2f, AvgSINR = %.2f, PF Metric = %.2f\n",
                   i + 1, sinr[i], avgSINR[i], pfMetric[i]);
        }

        // select highest PF metric user
        int selectedUser = selectUser(pfMetric);
        printf("User %d is scheduled (PF Metric = %.2f)\n", selectedUser + 1, pfMetric[selectedUser]);
    }

    return 0;
}

void updateAverageSINR(double *avgSINR, double currentSINR) {
    *avgSINR = S_F * currentSINR + (1 - S_F) * (*avgSINR);
}

int selectUser(double *pfMetric) {
    int selectedUser = 0;
    double maxMetric = -DBL_MAX;

    for (int i = 0; i < NUM_USERS; i++) {
        if (pfMetric[i] > maxMetric) {
            maxMetric = pfMetric[i];
            selectedUser = i;
        }
    }

    return selectedUser;
}

