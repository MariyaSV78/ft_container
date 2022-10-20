#!/bin/bash
echo "==============vector==============="
start=$(date +%s.%N)
  ./std_vector > result/std_vector.res
dur_std=$(echo "$(date +%s.%N) - $start" | bc)
printf "Execution time of the std_test: %.6f seconds\n" $dur_std

start=$(date +%s.%N)
  ./ft_vector > result/ft_vector.res 
dur_ft=$(echo "$(date +%s.%N) - $start" | bc)
printf "Execution time of the ft_test: %.6f seconds\n" $dur_ft

if  (( $(echo "$dur_ft < $dur_std * 20" |bc -l) ));
then
    echo -e "Time of execution of ft_vectors:           \033[32m OK \033[0m"
else
    echo -e "Time of execution of ft_vectors:           \033[31m KO \033[0m"       
fi

#diff ./result/std_vector.res ./result/ft_vector.res
if (diff -q ./result/std_vector.res ./result/ft_vector.res);
then
  echo -e "The std_vector and ft_vector are identical: \033[32m OK \033[0m"
else 
  echo -e "The std_vector and ft_vector are not identical: \033[31m OK \033[0m"
fi

echo "===============map================"
start=$(date +%s.%N)
  ./std_map > result/std_map.res
dur_std=$(echo "$(date +%s.%N) - $start" | bc)
printf "Execution time of the std_test: %.6f seconds\n" $dur_std

start=$(date +%s.%N)
  ./ft_map > result/ft_map.res 
dur_ft=$(echo "$(date +%s.%N) - $start" | bc)
printf "Execution time of the ft_test: %.6f seconds\n" $dur_ft

if  (( $(echo "$dur_ft < $dur_std * 20" |bc -l) ));
then
    echo -e "Time of execution of ft_map:         \033[32m OK \033[0m"
else
    echo -e "Time of execution of ft_map:       \033[31m KO \033[0m"       
fi

#diff ./result/std_map.res ./result/ft_map.res
if (diff -q ./result/std_map.res ./result/ft_map.res);
then
  echo -e "The std_map and ft_map are identical: \033[32m OK \033[0m"
else 
  echo -e "The std_map and ft_map are not identical: \033[31m OK \033[0m"
fi

echo "==============stack==============="
start=$(date +%s.%N)
  ./std_stack > result/std_stack.res
dur_std=$(echo "$(date +%s.%N) - $start" | bc)
printf "Execution time of the std_test: %.6f seconds\n" $dur_std

start=$(date +%s.%N)
  ./ft_stack > result/ft_stack.res 
dur_ft=$(echo "$(date +%s.%N) - $start" | bc)
printf "Execution time of the ft_test: %.6f seconds\n" $dur_ft

if  (( $(echo "$dur_ft < $dur_std * 20" |bc -l) ));
then
    echo -e "Time of execution of ft_stack:           \033[32m OK \033[0m"
else
    echo -e "Time of execution of ft_stack:         \033[31m KO \033[0m"       
fi

#diff ./result/std_stack.res ./result/ft_stack.res

if (diff -q ./result/std_stack.res ./result/ft_stack.res);
then
  echo -e "The std_stack and ft_stack are identical: \033[32m OK \033[0m"
else 
  echo -e "The std_stack and ft_stack are not identical: \033[31m OK \033[0m"
fi