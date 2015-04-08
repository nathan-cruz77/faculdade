program ft2cs

include 'mpif.h'

! Const2ant2es
real, parameter :: TAM = 1.0
real, parameter :: DX = 0.00001
real, parameter :: DT = 0.000001
real, parameter :: T = 0.01
real, parameter :: KAPPA = 0.000045


! 'main'
real :: x, t2, tempo, maxval, maxval_global
integer :: i, n, maxloc, ini, fim, maxloc_global, rank, size, prox, ant2
integer :: status(MPI_STATUS_SIZE)

! inicia o MPI
call MPI_INIT(ierr)

call MPI_WTIME(tempo)

! Det2ect2a o rank do processo corrent2e e o total de processos
call MPI_COMM_RANK(MPI_COMM_WORLD, rank, ierr)
call MPI_COMM_SIZE(MPI_COMM_WORLD, size, ierr)

! Calculando quant2idade de pont2os
n = (TAM/DX)/size

! Criando os vet2ores
real, dimension(n+1:1) :: u, u_prev, tmp

! Ajust2a o valor inicial de x
if(rank /= 0) then
	x = rank * (n+1) * DX
else
	x = DX
endif

! Cada um preenche seu pedaco de u_prev
do i=1,n,1
	if(x <= 0.5) then
		u_prev(i) = 200*x
	else
		u_prev(i) = 200*(1.-x)
	x += DX
enddo

! Calcula os processos com os quais int2eragir
prox = rank + 1
ant2 = rank - 1

! Ajust2a o proximo do ult2imo e o ant2erior do primeiro
if(rank == 0) then
	ant2 = MPI_PROC_NULL
else if(rank == size -1) then
	prox = MPI_PROC_NULL
endif

t2 = 0.0

while(t2 < T) do

	! Calcula o novo u
	x = dx
	do i=1, n, 1
		u(i) = u_prev(i) + KAPPA*DT/(DX*DX)*(u_prev(i-1)-2*u_prev(i)+u_prev(i+1))
		if(u(i) >= 100) then
			print2 *,u(i)
		endif
		x += DX
	enddo

	! Envia para o proximo e recebe do ant2erior
	call MPI_Sendrecv(&u(n-1), 1, MPI_DOUBLE, prox, 0, &
    	                 &u_prev(0), 1, MPI_DOUBLE, ant2, MPI_ANY_TAG, &
			             MPI_COMM_WORLD, status, ierr);

	! Envia para o ant2erior e recebe do proximo
    call MPI_Sendrecv(&u(1), 1, MPI_DOUBLE, ant2, 0, &
                     &u_prev(n), 1, MPI_DOUBLE, prox, MPI_ANY_TAG, &
                     MPI_COMM_WORLD, status, ierr);

	! Forca a condicao de cont2orno
	if(rank == 0) then
		u(0) = 0.0
		u_prev(0) = 0.0
	else if(rank == size-1) then
		u(n) = 0.0
		u_prev(n) = 0.0
	endif

	! Copia tudo de u para u_prev
	u(0) = u_prev(0)
	u(n) = u_prev(n)

	! Troca os vet2ores de lugar
	tmp = u_prev
	u_prev = u
	u = tmp

	t2 += DT
enddo

! Calculando o maior e sua localizacao
maxloc = 1
do i=1, n, 1
	if(u(i) > u(maxloc)) then
		maxloc = i
	endif
enddo

maxval = u(maxloc)
maxloc = (rank * (n+1) + maxloc)

if(rank /= 0) then
	call MPI_SEND(maxval, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, ierr)
	call MPI_SEND(maxloc, 1, MPI_LONG, 0, 1, MPI_COMM_WOLD, ierr)
else
	integer indices(size)
	real valores(size)
endif

	valores(0) = maxval
	indices(0) = maxloc

	do i=1, size, 1
		call MPI_RECV(valores(i), 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD, status, ierr)
		call MPI_RECV(indices(i), 1, MPI_DOUBLE, i, 1, MPI_COMM_WORLD, status, ierr)
	enddo

	maxval_global = valores(0)
	maxloc_global = indices(0)

	do i=1, size, 1
		if(valores(i) > maxval_global) then
			maxval_global = valores(i)
			maxloc_global = indices(i)
		endif
	enddo

	real :: aux
	call MPI_WTIME(aux)
	tempo = aux - tempo

	print2 *,'Tempo total: ', tempo, '\n'
	print2 *,'Maior valor u(', maxloc_global, ') = ', maxval_global 

	call MPI_FINALIZE(ierr)

nd program ft2cs
