#include <iostream>
#include <vector>
template<typename T>
class PrettyPrinter {
	T *m_pData;
public:
	PrettyPrinter(T *data) :m_pData(data) {

	}
	void Print() {
		std::cout << "{" << *m_pData << "}" << std::endl;
	}

	T * GetData() {
		return m_pData;
	}
};

//Explicit specialization of a member function should appear outside the class
template<>
void PrettyPrinter<std::vector<int>>::Print() {
	std::cout << "{";
	for (const auto &x : *m_pData) {
		std::cout << x;
	}
	std::cout << "}" << std::endl;
}

template<>
void PrettyPrinter<std::vector<std::vector<int>>>::Print() {
    std::cout << "{" << std::endl;
    std::size_t vectorSize = m_pData->size();

    for (const auto &vec : *m_pData) {
        std::cout << "\t{";  
        std::size_t elementSize = vec.size();

        for (const auto &el : vec) {
            std::cout << el;
            if (elementSize > 1) std::cout << ",";
            elementSize--;
        }

        std::cout << "}";
        if (vectorSize > 1) std::cout << ",";
        std::cout << std::endl;
        vectorSize--;
    }
    std::cout << "}" << std::endl;
}


template<>
class PrettyPrinter<char*> {
	char *m_pData;
public:
	PrettyPrinter(char *data) :m_pData(data) {

	}
	void Print() {
		std::cout << "{" << m_pData << "}" << std::endl;
	}
	char * GetData() {
		return m_pData;
	}
};

//template<>
//class PrettyPrinter<std::vector<int>> {
//	std::vector<int> *m_pData;
//public:
//	PrettyPrinter(std::vector<int> *data) :m_pData(data) {
//
//	}
//	void Print() {
//		std::cout << "{";
//		for (const auto &x : *m_pData) {
//			std::cout << x;
//		}
//		std::cout << "}" << std::endl;
//	}
//	std::vector<int> * GetData() {
//		return m_pData;
//	}
//};
int main() {
	//int data = 5;
	//float f = 8.2f;
	//PrettyPrinter<int> p1(&data);
	//p1.Print();
	//PrettyPrinter<float> p2(&f);
	//p2.Print();

	// char *p{ "Hello world" };
	// PrettyPrinter<char*> p3(p);
	// p3.Print();
	// char *pData = p3.GetData();
	// std::vector<int> v{ 1,2,3,4,5 };
	// PrettyPrinter<std::vector<int>> pv(&v);
	// pv.Print();

    std::vector<std::vector<int>> vecVec{
        {1, 2, 3},
        {4, 5, 6, 7, 8}
    };
    PrettyPrinter<std::vector<std::vector<int>>> ppVecVec(&vecVec);
    std::cout << "Printing vector<vector<int>>:" << std::endl;
    ppVecVec.Print();
    std::cout << std::endl;

    return 0;

}