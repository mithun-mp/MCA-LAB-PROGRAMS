#!/bin/bash
echo " PID PROCESS NAME"
ps -e|while read pid tty time cmd
do
echo $pid $tty $time $cmd
done
