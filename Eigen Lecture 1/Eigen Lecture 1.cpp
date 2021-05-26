// Eigen Lecture 1.cpp : Defines the entry point for the application.
//

#include "Eigen Lecture 1.h"

using namespace std;

int main()
{
	Eigen::Matrix<float, 2, 2> nameMatr;
	nameMatr << 1, 2, 3, 4;
	std::cout << "Use matrix 4 x 4" << std::endl;
	Eigen::Matrix4f nameMat;
	nameMat << 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16;
	std::cout << "Show 4x4 matrix \:t[ \n "<<nameMat;
	std::cout << "]" << std::endl;
	std::cout << "Test Vector column " << std::endl;
	Eigen::Vector3f vectorColumn;
	vectorColumn<< 1, 2, 4;
	std::cout << "Show vector \t:[ " << vectorColumn << "]" << std::endl;
	std::cout << "Row vector " << std::endl;
	Eigen::RowVector2f row; 
	row << 1, 2;
	std::cout << "Show vector \t:[ " << row << "]" << std::endl;

	std::cout << "Special case for dynamic size" << std::endl;
	Eigen::Matrix<float,3,Eigen::Dynamic> dynamic;
	Eigen::MatrixXd allocateArra(10, 15); //150 element 
	std::cout << "Show size dynamic matrix \t: [" << allocateArra.size() << "]" << std::endl;
	std::cout << "Allocate dynamic column vector " << std::endl;
	Eigen::VectorXf vecTen(10);
	std::cout << "Show size dynamic vector \t: [" <<vecTen.size() << "]" << std::endl;
	std::cout << "Initialized from list coefficients" << std::endl;
	Eigen::Vector2d twoDimen(8.0, 9.0);
	std::cout << "Show vector from list initialized \t: [  \n" << twoDimen << "\n]" << std::endl;
	std::cout << "Hello Eigen\n" <<nameMatr << endl;

	Eigen::MatrixXd input(2, 2);
	std::cout << "Input Matrix \t: [";
	for (auto i = 0; i != 2; ++i) {
		for (auto j = 0; j != 2; ++j) {
			//testing input from user 
			//std::cin >> input(i, j);
			input(i, j) = i * j + 12;
		}
	}
	std::cout << "Result matrix \t: [ \n" << input;
	std::cout << "]" << std::endl;
	std::cout << "Result transpose \t: [ \n" << input.transpose();
	std::cout << "]" << std::endl;

	std::cout << "Input Vector \t: [";
	Eigen::VectorXd interAct(9);
	auto inVec = 0;
	while (inVec!=interAct.size())
	{
		interAct(inVec) = inVec+2*4;
		++inVec;
	}
	std::cout << "Show vector \t:  [ " << interAct <<"]"<<std::endl;
	std::cout << "Show the norm \t: [" << interAct.norm() << "]" << std::endl;
	std::cout << "Test assign the eigen vector to standart vector in c++" << std::endl;
	Eigen::VectorXi vecIni(10); //contain 10 element , column vector 
	for (auto i = 0; i != vecIni.size();++i) {
		vecIni(i) = 2 * i * 34;
	}
	std::vector<double> assign;
	for (auto i = 0; i != vecIni.size(); ++i) {
		assign.push_back(vecIni(i));
	}

	std::cout << "After assign eigen matrix  to standart vector\t:[ ";
	for (auto& i : assign)
	{
		std::cout << i << "|";
	}
	std::cout << "]" << std::endl;
	
	std::cout << "vice versa of the operation" << std::endl;
	std::vector<int> findNorm{ 10,28,37,47,6,7,8,4,1 };
	Eigen::VectorXd destNorm(9);
	for (size_t i = 0; i != findNorm.size(); ++i)
	{
		destNorm(i) = findNorm[i];
	}

	std::cout << "Show matrix to find \t: [";
	for (auto& i : findNorm)
	{
		std::cout << i << "|";
	}
	std::cout << "]" << std::endl; 
	std::cout << "And it has norm  \t: [" << destNorm.norm() << "]" << std::endl;
	
	std::cout << "Resize matrix" << std::endl;
	Eigen::MatrixXi resize(8, 4);
	std::cout << "current row \t:[" << resize.rows() << "\tand col \t: " << resize.cols() << "]" << std::endl;
	std::cout << "After resizing the current matrix " << std::endl;
	resize.resize(8, 6);
	std::cout << "current row \t:[" << resize.rows() << "\tand col \t: " << resize.cols() << "]" << std::endl;
	std::cout << "Test resize vector " << std::endl;
	Eigen::VectorXi nameTore(9);
	std::cout << "Before resing the current vector" << std::endl;
	std::cout << "current row \t:[" << nameTore.rows() << "\tand col \t: " << nameTore.cols() << "]" << std::endl;
	nameTore.resize(19);
	std::cout << "After resizing the current vector" << std::endl;
	std::cout << "current row \t:[" << nameTore.rows() << "\tand col \t: " << nameTore.cols() << "]" << std::endl;
	
	std::cout << "Assignments and resizing" << std::endl;
	Eigen::MatrixXd doubleTwo(2, 2);
	std::cout << "Matrix size , current row \t: [ " << doubleTwo.rows() << " and cols \t: " << doubleTwo.cols() << "]" << std::endl;
	Eigen::MatrixXd doubleThree(3, 3);
	std::cout << "Matrix size , current row \t: [ " << doubleThree.rows() << " and cols \t: " << doubleThree.cols() << "]" << std::endl;
	doubleTwo = doubleThree;
	std::cout << "After assign the matrix" << std::endl;
	std::cout << "Matrix size , current row \t: [ " << doubleTwo.rows() << " and cols \t: " << doubleTwo.cols() << "]" << std::endl;
	std::cout << "Using fix sized for matrix less than 16 or more " << std::endl;
	Eigen::Matrix<int, 15, 15> fifteen;
	
	std::default_random_engine generator;
	std::binomial_distribution<int> distribution(198, 0.5);
	for (auto i = 0; i != fifteen.rows(); ++i) {
		for (auto j = 0; j != fifteen.cols(); ++j) {
			fifteen(i, j) = distribution(generator);
		}
	}
	std::cout << "Result matrix after generate random (binomial distribution)" << std::endl;
	std::cout<<fifteen<<std::endl;
	std::vector<std::vector<int>> secDimen(5,std::vector<int> (5,distribution(generator)));

	/*for (size_t i = 0; i !=8; ++i)
	{
		for (size_t j = 0; j != 8; ++j) {
			secDimen[i][j] = distribution(generator);
		}
	} */
	//my style initilized at runtime 
	for (auto& i : secDimen)
	{
		for (auto& j : i) {
			j = distribution(generator);
		}
	}

	std::cout << "Explorer vector template for 2 dimension" << std::endl;
	for (auto& i : secDimen)
	{
		for (auto& j : i) {
			std::cout << j << "|";
		}
		
		std::cout << std::endl;

	}
	std::cout << "]" << std::endl;

	//another way 

	std::vector<std::vector<int>> vecDis{ {11,22,31},{11,21,32} };
	std::cout << "Show the new style" << std::endl;
	for (auto& i : vecDis)
	{
		for (auto& j : i) {
			std::cout << j << "|";
		}
		std::cout << std::endl;
	}
	std::cout << "]" << std::endl;

	return 0;
}
