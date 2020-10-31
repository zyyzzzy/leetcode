/*给定一个矩阵 A， 返回 A 的转置矩阵。

矩阵的转置是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。

 

示例 1：

输入：[[1,2,3],[4,5,6],[7,8,9]]
输出：[[1,4,7],[2,5,8],[3,6,9]]
示例 2：

输入：[[1,2,3],[4,5,6]]
输出：[[1,4],[2,5],[3,6]]
 

提示：

1 <= A.length <= 1000
1 <= A[0].length <= 1000
*/

class Solution {
public:

    vector<vector<int>> transpose(vector<vector<int>>& A) {

       int row = A.size();//最外面的中括号即二维数组的行数(容器中的元素数目)
       int col = A[0].size();//容器中的第一个元素的元素数目
       
       vector<vector<int>> B;//定义一个输出为A的转置的二维数组B；

       if(A.empty())    return B;
       for(int j=0;j<col;j++)
       {
           vector<int>tmp;//定义一个容器
           for(int i=0;i<row;i++)
           {
               tmp.push_back(A[i][j]);//将第一列元素放入tmp容器中。
           }    
           B.push_back(tmp);
       }
       return B;
    }
};