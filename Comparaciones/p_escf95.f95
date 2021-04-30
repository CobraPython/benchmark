program p_esc
!declaracion de variables
implicit none
integer::i,j,l
real(16)::st,fn
!integer,dimension(19)::N=(/(10**5+i*5550000,i=0,18)/)
integer,dimension(14)::N=(/100000,143844,206913,297635,428133,615842,885866,1274274,&
1832980,2636650,3792690,5455594,7847599,11288378/)
real,dimension(100)::t
real(16)::avg,s
real,dimension(:), allocatable::v1,v2,v3
open(1,file='dataf.csv',status='new')
write(1,*) "N elementos procesados, ","Tiempo promedio(ms), "
do i=1,14
	s=0
	call srand(N(i))
	do j=1,100
		allocate(v1(N(i)))
		allocate(v2(N(i)))
		allocate(v3(N(i)))
		do l=1,N(i)
			v1(l)=rand()
			v2(l)=rand()
		end do
		call cpu_time(st)
		v3=v1*v2
		call cpu_time(fn)
		deallocate(v1)
		deallocate(v2)
		deallocate(v3)
		s=s+fn-st
	end do
	avg=s/100
	write(1,*) N(i),avg
end do
close(1)
end program
