#include<stdio.h>

typedef struct process {
	int Id, AT, BT, CT, TAT, WT, RT;
} pro;

pro p[15];

void swap(pro *a, pro *b) {
	pro temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int n) {
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < n - i - 1; j++) {
			if(p[j].AT > p[j + 1].AT) {
				swap(&p[j], &p[j + 1]);
			}
		}
	}
}

void main() {
	int n, total_WT = 0, total_TAT = 0, total_RT = 0;
	float avg_WT = 0, avg_TAT = 0, avg_RT = 0;

	printf("Enter the number of processes: ");
	scanf("%d", &n);

	printf("\nEnter the arrival time and burst time of the process:\n");
	printf("AT BT\n");
	for(int i = 0; i < n; i++) {
		p[i].Id = i + 1;
		scanf("%d%d", &p[i].AT, &p[i].BT);
	}

	sort(n);

	int curTime = 0;
	printf("\nGantt Chart:\n");

	for(int i = 0; i < n; i++) {
		if(p[i].AT > curTime){
			printf("| Idle (%d-%d) ", curTime, p[i].AT);
			curTime = p[i].AT;
		}
		
		p[i].RT = curTime - p[i].AT;
		curTime += p[i].BT;
		p[i].CT = curTime;
		p[i].TAT = p[i].CT - p[i].AT;
		p[i].WT = p[i].TAT - p[i].BT;

		total_TAT += p[i].TAT;
		total_WT += p[i].WT;
		total_RT += p[i].RT;

		printf("| P%d (%d) %d", p[i].Id, p[i].BT, curTime);
	}

	avg_TAT = (float)total_TAT / n;
	avg_WT = (float)total_WT / n;
	avg_RT = (float)total_RT / n;

	printf("\n\nObservation Table\n");
	printf("PID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
	for(int i = 0; i < n; i++) {
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].Id, p[i].AT, p[i].BT, p[i].CT, p[i].TAT, p[i].WT, p[i].RT);
	}

	printf("\nAverage Waiting Time = %.2f\n", avg_WT);
	printf("Average Turnaround Time = %.2f\n", avg_TAT);
	printf("Average Response Time = %.2f\n", avg_RT);
}

