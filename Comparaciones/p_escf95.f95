program p_esc
!declaracion de variables
implicit none
integer::i,j,l
real(16)::st,fn !para medir el timepo inicio y final
!datos copiados de los otros programas
integer,dimension(20)::N !No corria con todos los datos, no tengo idea por que, lo hice por grupos
real(16)::avg,s
real,dimension(:), allocatable::v1,v2,v3 !vectores dinamicos
open(1,file='dataf.csv',status='new')
write(1,*) "N elementos procesados, ","Tiempo promedio(ms), "
do i=1,20
	s=0
	call srand(N(i)) !numeros aleatorios
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
	avg=s/100 !promedio
	write(1,*) N(i),avg
end do
close(1)
end program
