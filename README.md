# Proportional Fair (PF) Metric


## Formula:
- For a user : PF Metric =  Instantaneous SINR / Average SINR 
## Where:  
1. Instantaneous data rate (or SINR) of user  at time .
2. Average data rate (or SINR) of user  up to time .

## Explanation:
- Users with a low average SINR () but good current SINR () will have a higher PF Metric, making them more likely to be scheduled.
- This ensures fairness while leveraging good channel conditions.

# Exponential Moving Weighted Average (EMWA)

## Formula: 
![image](https://github.com/user-attachments/assets/d5707dc6-4076-439a-9795-c0c8ca7b7f0d)


## Where:

1. Updated average SINR for user  at time .
2. Current instantaneous SINR for user  at time .
3. Previous average SINR for user .
4. Smoothing factor .
5. Places more emphasis on recent SINR values.
6. Places more emphasis on historical SINR values.

## Explanation:

- EMWA ensures that the average SINR quickly reflects recent changes in channel conditions while maintaining stability.
- The smoothing factor  controls the balance between recent and historical SINR values.
