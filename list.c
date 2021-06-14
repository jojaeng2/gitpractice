#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _intlinked {		//_intlinked 구조체 정의
	int num;
	struct _intlinked* next;
}il;		// _intlinked 구조체의 별칭을 il 이라고 지정

il* make_node() {		// 헤더를 만드는 함수
	il* newnode = (il*)malloc(sizeof(il));
	newnode->next = NULL;		// 새로 생성되는 리스트의 next는 항상 NULL
	return newnode;				// 해로 생성되는 리스트(헤더)를 반환
}

void add_node(il* head, int value) {		//선입선출 방식으로 리스트를 추가해주는 함수
	il* newnode = (il*)malloc(sizeof(il));	// 새로운 리스트를 할당
	il* cur = head;					// 반복을 위한 포인터변수
	while (cur != NULL) {			// 헤더부터 시작해서
		if (cur->next == NULL) {	// next가 NULL인 노드의 
			cur->next = newnode;	// next 값을 새로 생성된 리스트로 수정
			newnode->next = NULL;	// 새로 생성되는 리스트의 next는 항상 NULL
			newnode->num = value;	// 새로 생성되는 리스트에 값을 넣어줌
		}
		cur = cur->next;	//if 문을 수행하면 cur의 next는 NULL이기 때문에 반복문은 여기까지만 수행됨
	}
}

// 구조체 포인터변수 h를 NULL로 설정
void destroyall(il* head) {		// 할당받은 메모리를 모두 반납해주는 함수
	il* h = head->next;
	while (h->next != NULL) {	// h가 리스트의 끝에 도달할 때까지 반복
		il* next = h->next;		// 다음 줄에서 h변수에 할당된 메모리가 사라지므로 h의 다음노드를 next변수에 저장
		free(h);				// h(연결리스트) 메모리 해제 
		h = next;				// 해제되기전 h의 다음 노드를 저장했던 next를 h로 다시 불러옴
	}
}

int main() {
	il* head = NULL;		// head의 초기값을 NULL로 설정
	if (head == NULL) {		// head가 NULL일 경우 head는 최초로 생성되는 리스트를 가리킴
		head = make_node();	//	(head를 리스트의 이름이라고 생각할 수도 있을 것 같음)
	} 
	int n, i, value;
	printf("생성할 리스트의 개수 입력: "); scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("정수를 입력하세요: "); scanf("%d", &value);
		add_node(head, value);		//head 리스트에 먼저 입력된 값이 먼저 나오도록 노드를 추가하는 함수 실행
	}
	il* a = head->next;
	while (a != NULL) {		//리스트의 값들을 입력된 순서대로 출력함
		printf("저장된 정수: %d\n", a->num);
		a = a->next;
	}
	destroyall(head);	// head 리스트에서 값을 저장하던 노드들의 메모리 해제
	free(head);			// head의 헤더 메모리 해제

	return 0;
}
