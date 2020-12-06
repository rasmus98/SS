program problem3
    implicit none

    Integer, parameter :: n = 1000000
    real :: rate = 0.01, specificity = 0.993, sensitivity = 0.998
    real, dimension(n) :: r
    logical :: allergic(n), positive(n)
    call random_number(r)
    allergic = r<rate
    call random_number(r)
    where (allergic)
        positive = sensitivity > rand() 
    elsewhere
        positive = 1-specificity > rand()
    endwhere
    
    print *, "3a:"
    print *, "P(T=1)=", 1.*count(positive)/n
    print *, "P(T=-1)=", 1.*count(.not.positive)/n
    print *, "3b:"
    print *, "P(A=0|T=1)=", 1.*count(.not.allergic .and. .not.positive)/count(.not.positive)
    print *, "3c:"
    print *, "P(A=1|T=1)=",1.*count(allergic .and. positive)/count(positive)
end program problem3