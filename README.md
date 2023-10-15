# std::all_of Testing Lab

Explore the `std::all_of` function on different volumes of data, with different policies, and with different predicates. In particular, investigate:
1) the performance of the library algorithm in the absence of a policy;
2) the performance of the library algorithm with different policies;
3) the performance of your own parallel algorithm when using a different number of threads.

Build your own algorithm that divides the data collection into K parts of approximately equal length, processes each part in a separate thread (using a sequential library algorithm), and then combines the result (using a sequential library algorithm). Print the running time's dependence on the parameter K's value.
