set datafile separator ","
set terminal png size 900,400
set title "State Estimation gyro_x = accel_x = sin(x)"
set ylabel "euler angle"
set xlabel "Time"
set xdata time
set timefmt "%s"
set key left top
plot "simulator.dat" using 1:2 title 'g_x' with lines, \
     "simulator.dat" using 1:5 title 'a_x' with lines, \
     "simulator.dat" using 1:8 title 'roll' with lines, \
     "simulator.dat" using 1:9 title 'pitch' with lines, \
     "simulator.dat" using 1:10 title 'yaw'
