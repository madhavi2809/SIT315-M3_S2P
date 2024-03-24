#include <mpi.h>
#include <stdio.h>

int main(int argc, char * argv[]) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        // Master process
        char message[] = "Hello, World!";
        // Broadcast the message to all worker processes
        MPI_Bcast(message, sizeof(message), MPI_CHAR, 0, MPI_COMM_WORLD);
    } else {
        // Worker processes
        char recv_message[100]; // Assuming max message length is 100 characters
        // Receive the broadcast message from the master process
        MPI_Bcast(recv_message, sizeof(recv_message), MPI_CHAR, 0, MPI_COMM_WORLD);
        printf("Process %d received broadcast message: %s\n", rank, recv_message);
    }

    MPI_Finalize();
    return 0;
}
