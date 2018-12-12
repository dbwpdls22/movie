
void* mv_genMvInfo(char* name, float score, int runTime, char* country);//영화 정보를 구조체 형태로 받는 함수 
void mv_print(void* obj);//구조체를 출력하는 함수
float mv_getScore(void* obj);//구조체의 멤버인 평점을 추출하는 함수 
int mv_getRunTime(void* obj);//구조체의 멤버인 러닝타임을 추출하는 함수 
char* mv_getName(void* obj);//구조체의 멤버인 영화 제목을 추출하는 함수 
char* mv_getCountry(void* obj);//구조체의 멤버인 제작 국가를 추출하는 함수 
