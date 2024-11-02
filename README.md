# Dynamic Array in C++ (Custom Vector Implementation)

## Overview
This repository contains a custom implementation of a dynamic array in C++, similar to `std::vector`, using C-style arrays. The dynamic array supports basic operations like inserting elements, accessing elements, and resizing when the capacity is reached.

The implementation demonstrates the amortized runtime analysis of a dynamic table that doubles in size when full, as discussed in *Introduction to Algorithms, Third Edition* by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein.

## Dynamic Array Implementation

### Key Features
- **Automatic resizing**: The array doubles its capacity when it's full.
- **Element access**: Retrieve and modify elements at specific indices.
- **Push back operation**: Add elements to the end of the array.

## Amortized Runtime Analysis

To analyze the amortized runtime of inserting \( n \) elements into a dynamic table that doubles in size when it reaches capacity, we apply two methods: the **aggregate method** and the **accounting method**. This analysis is based on Section 17.4 of *Introduction to Algorithms, Third Edition* by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein.

### Problem Statement
A dynamic table doubles in size whenever it runs out of capacity. We want to determine the amortized runtime for inserting \( n \) elements.

### a) Aggregate Method

In the aggregate method, we calculate the total cost for \( n \) insertions and then divide by \( n \) to determine the amortized cost per insertion.

1. **Cost of regular insertions**: Each insertion costs \( O(1) \) if there’s space available in the table.
2. **Cost of resizing**: When the table reaches full capacity, it doubles in size. This requires copying all existing elements, leading to a cost proportional to the number of elements, \( O(n) \), at each resize.

To find the total cost for \( n \) insertions:
- Inserting the first \( n/2 \) elements involves no resizing, so each of these has a cost of \( O(1) \).
- For the remaining \( n/2 \) elements, the table resizes as needed, with each resize costing a sum of elements copied that forms a geometric series.

Thus, the total cost \( T(n) \) is:
\[
T(n) = O(n) + O\left(\frac{n}{2}\right) + O\left(\frac{n}{4}\right) + \dots + O(1) = O(2n) = O(n)
\]

**Amortized Cost per Operation**:
\[
\frac{O(n)}{n} = O(1)
\]

Therefore, the amortized runtime per insertion using the aggregate method is **\( O(1) \)**.

### b) Accounting Method

In the accounting method, we assign "credits" to each insertion operation to cover the costs of future resizes.

1. **Credit Assignment**: We assign an **amortized cost of 3 credits** to each insertion.
   - Each regular insertion uses **1 credit** for the insertion itself and saves **2 extra credits** for future resizing.
   
2. **Credit Usage During Resizing**: When resizing the table (doubling its capacity), we need to copy each element from the old table to the new one. The saved credits from previous insertions pay for this cost:
   - For example, resizing from a capacity of \( k \) to \( 2k \) involves copying \( k \) elements, which are covered by the 2 saved credits per element, totaling \( 2k \) credits.

**Amortized Cost per Insertion**:
With 3 credits per insertion, we cover both the insertion cost and future resizing costs, yielding an amortized cost per operation of **\( O(1) \)**.

### Conclusion
Using both the **aggregate method** and the **accounting method**, we find that the amortized cost per insertion for a dynamic table that doubles in size is **\( O(1) \)**.
