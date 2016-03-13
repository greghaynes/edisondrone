set datafile separator ","
set terminal png size 1800,800
set title "State Estimation gyro = sin(x)"
set ylabel "radian / second"
set xlabel "Time"
set xdata time
set timefmt "%s"
set key left top
plot "simulator.dat" using 1:2 lw 1 title 'gyro_x' with lines, \
     "simulator.dat" using 1:5 lw 1 title 'accel_x' with lines, \
     "simulator.dat" using 1:6 lw 1 title 'accel_y' with lines, \
     "simulator.dat" using 1:7 lw 1 title 'accel_z' with lines, \
     "simulator.dat" using 1:8 lw 1 title 'roll' with lines, \
     "simulator.dat" using 1:9 lw 1 title 'pitch' with lines
