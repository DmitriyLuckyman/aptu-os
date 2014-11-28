#!/usr/bin/env python3

import subprocess

def get_time(n, m):
    if m == 1:
        out = subprocess.Popen(['./sieve_unith', str(n)], stdout=subprocess.PIPE).communicate()
    else:
        out = subprocess.Popen(['./sieve_multith', str(n), str(m)], stdout=subprocess.PIPE).communicate()
    return float(out[0].split()[0])

def get_time_multith(n, m):
    out = subprocess.Popen(['./sieve_multith', str(n), str(m)], stdout=subprocess.PIPE).communicate()
    return float(out[0].split()[0])

def fill_task1_data():
    task1_data_file = open("TASK1_DATA", "w")

    for M in range(1, 20 + 1):
        for N in range(1, 10**5, 1000):
            result = get_time(N, M)
            task1_data_file.write(str(M) + "; " + str(N) + "; " + str(result) + "\n")

def fill_task2_data():
    task1_data_file = open("TASK2_DATA", "w")
    for N in range(1, 10**5, 1000):
        result_unith = get_time(N, 1)
        result_multith = get_time_multith(N, 1)
        task1_data_file.write(str(result_unith) + " | " + str(result_multith) + "; " + str(N) + "\n")

if __name__ == '__main__':
    fill_task1_data()
    fill_task2_data()
    
    plot = subprocess.Popen(['gnuplot'], stdin=subprocess.PIPE)
    plot.communicate(b"""
    splot 'TASK1_DATA' using 1:2:3 '%lf;%lf;%lf' with linespoints pt 0 ps 1 lw 1
    pause 100
    """)
