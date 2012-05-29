#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int testCases, labels, edges, master_vertices, i, from, to;
	bool visited;
	vector<vector<int> > edgeMatrix;
	queue<int> master_jumplist;
	vector<bool> reachable;
	cin >> testCases;
	start:
	static void* master_table[] = {&&read_test_input, &&done};
	goto *master_table[testCases-- < 1];
	
	read_test_input:
	static void* read_test_input_table[] = {&&not_zero, &&zero};
	cin >> labels >> edges >> master_vertices;
	goto *read_test_input_table[labels == 0 || master_vertices == 0 || edges == 0];
	
	not_zero:
	edgeMatrix = vector<vector<int> > (labels, vector<int>(labels, 0));
	//master_jumplist = vector<int>(master_vertices);
	reachable = vector<bool> (labels, false);
	i = 0;
	goto test_input_loop;
	
	zero:
	cout << "0" << endl;
	goto start;
	
	// cout << "Read values: " << labels << " | " << edges << " | " << master_vertices << endl;
	// goto *test_table[0];
	
	test_input_loop:
	static void* test_input_loop_table[] = { &&read_edge_line, &&read_table_line, &&start_bfs };
	goto *test_input_loop_table[(i >= edges) + (i++ >= edges + master_vertices)];
	
	read_edge_line:
	cin >> from >> to;
	edgeMatrix[from-1][to-1] = 1;
	goto test_input_loop;
	
	read_table_line:
	cin >> from;
	master_jumplist.push(from-1);
	goto test_input_loop;
	
	start_bfs:
	static void* start_bfs_table[] = { &&do_bfs, &&print_test_output };
	// from this point, master_jumplist is used as a queue of vertices to visit - DON'T FORGET TO EMPTY IN THE END!!!
	goto *start_bfs_table[master_jumplist.empty()];
	
	do_bfs:
	static void* do_bfs_table[] = { &&check_vertices, &&start_bfs };
	from = master_jumplist.front();
	master_jumplist.pop();
	i = 0;
	goto *do_bfs_table[reachable[from]];
	
	check_vertices:
	static void* check_vertices_table[] = { &&cont, &&is_reachable };
	goto *check_vertices_table[edgeMatrix[from][i]];
	
	is_reachable:
	static void* is_reachable_table[] = { &&enqueue, &&cont };
	goto *is_reachable_table[reachable[i]];
	
	enqueue:
	static void* enqueue_table[] = { &&current_node_done, &&check_vertices };
	master_jumplist.push(i);
	goto *enqueue_table[i++ < labels];
	
	cont:
	static void* cont_table[] = { &&current_node_done, &&check_vertices };
	goto *cont_table[i++ < labels];
	
	current_node_done:
	reachable[from] = true;
	goto start_bfs;
	
	print_test_output:
	i = 0;
	to = 0; // to will be our count of reachable vertices
	goto count_reachable;
	
	count_reachable:
	static void* count_reachable_table[] = { &&actual_print, &&count_reachable };
	to += (int) reachable[i];
	goto *count_reachable_table[i++ < labels];
	
	actual_print:
	static void* actual_print_table[] = { &&empty_queue, &&start};
	cout << to << endl;
	goto *actual_print_table[master_jumplist.empty()];
	
	empty_queue:
	static void* empty_queue_table[] = { &&empty_queue, &&start};
	master_jumplist.pop();
	goto *empty_queue_table[master_jumplist.empty()];
	
	done:
	i = 42;
}