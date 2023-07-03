It is solving the Dining Philosophers problem.

The program takes 5 to 6 parameters:
./philo/$ ./philo ${No. of philosophers} ${Time they can stay alive before eating} ${Time required to eat} ${Time required to sleep} ${(optional) No. of times each philosopher has to eat to stop simulation}

example:
$ ./philo 3 200 100 100 \n
0 1 picked up fork
0 1 picked up fork
0 1 is eating
100 1 is sleeping
100 3 picked up fork
100 3 picked up fork
100 3 is eating
200 3 is sleeping
200 1 is thinking
200 2 picked up fork
200 2 picked up fork
200 2 is eating
202 1 died
