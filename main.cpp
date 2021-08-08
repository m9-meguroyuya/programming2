#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>

//選手のクラス
class LFC_Player {
protected:
    int _num;
    std::string _position;
    std::string _name;
    
public:
    LFC_Player(){}
    void setNum(int num) { _num = num; }
    void setPosition(std::string position) { _position = position; }
    void setName(std::string name) { _name = name; }
    void show(){std::cout << "Position:"<< _position << ", No." << _num << ", Name:" << _name << "\n\n";}
};

//シード値をランダムで定める関数
int Seed(){
    int num;
    num = rand() % 1000000;
    return num;
};

//ゴールキーパの情報を登録・表示し，ランダムに1人を選ぶ関数
void LFC_GK() {
    std::vector<LFC_Player> playerGK;
    
    //ゴールキーパの情報を登録
    std::ifstream infile("lfc_gk.txt");
    int numgk;
    std::string positiongk;
    std::string namegk;
    
    while (infile >> positiongk >> numgk >> namegk) {
        playerGK.emplace_back();
        playerGK[playerGK.size() -1].setNum(numgk);
        playerGK[playerGK.size() -1].setPosition(positiongk);
        playerGK[playerGK.size() -1].setName(namegk);
    }
    infile.close();
    
    //ゴールキーパの一覧を表示
    printf("[check GOALKEEPERS:Enter] > ");
    getchar();
    printf("\n");
    std::cout << "-GOALKEEPERS-------------------------------------------\n" << std::endl;
    for(auto i = playerGK.begin() ; i != playerGK.end(); i++) i->show();
    
    //ゴールキーパをランダムに1人選ぶ
    printf("\n[select GOALKEEPER:Enter] > ");
    getchar();
    printf("\n");
    srand(static_cast<unsigned int>(time(NULL)));
    std::vector<int> vecGK{ 0, 1, 2, 3 };
    std::mt19937 get_rand_mt(Seed());
    std::shuffle( vecGK.begin(), vecGK.end(), get_rand_mt );
    int gk1=vecGK[0];
    printf("~selected GK~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    playerGK[gk1].show();
    printf("-------------------------------------------------------\n");
}

//ディフェンダーの情報を登録・表示し，ランダムに4人を選ぶ関数
void LFC_DF() {
    std::vector<LFC_Player> playerDF;
    
    //ディフェンダーの情報を登録
    std::ifstream infile("lfc_df.txt");
    int numdf;
    std::string positiondf;
    std::string namedf;
    
    while (infile >> positiondf >> numdf >> namedf) {
        playerDF.emplace_back();
        playerDF[playerDF.size() -1].setNum(numdf);
        playerDF[playerDF.size() -1].setPosition(positiondf);
        playerDF[playerDF.size() -1].setName(namedf);
    }
    infile.close();
    
    //ディフェンダーの一覧を表示
    printf("[check DEFENDERS:Enter] > ");
    getchar();
    printf("\n");
    std::cout << "-DEFENDERS---------------------------------------------" << "\n" << std::endl;
    for(auto j = playerDF.begin() ; j != playerDF.end(); j++) j->show();
    
    //ディフェンダーをランダムに4人選ぶ
    printf("\n[select DEFENDERS:Enter] > ");
    getchar();
    printf("\n");
    srand(static_cast<unsigned int>(time(NULL)));
    std::vector<int> vecDF{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::mt19937 get_rand_mt(Seed());
    std::shuffle( vecDF.begin(), vecDF.end(), get_rand_mt );
    int df1=vecDF[0];
    int df2=vecDF[1];
    int df3=vecDF[2];
    int df4=vecDF[3];
    printf("~selected DF~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    playerDF[df1].show();
    playerDF[df2].show();
    playerDF[df3].show();
    playerDF[df4].show();
    printf("-------------------------------------------------------\n");
}

//ミッドフィルダーの情報を登録・表示し，ランダムに3人を選ぶ関数
void LFC_MF() {
    std::vector<LFC_Player> playerMF;
    
    //ミッドフィルダーの情報を登録
    std::ifstream infile("lfc_mf.txt");
    int nummf;
    std::string positionmf;
    std::string namemf;
    
    while (infile >> positionmf >> nummf >> namemf) {
        playerMF.emplace_back();
        playerMF[playerMF.size() -1].setNum(nummf);
        playerMF[playerMF.size() -1].setPosition(positionmf);
        playerMF[playerMF.size() -1].setName(namemf);
    }
    infile.close();
    
    //ミッドフィルダーの一覧を表示
    printf("[check MIDFIELDERS:Enter] > ");
    getchar();
    printf("\n");
    std::cout << "-MIDFIELDERS-------------------------------------------" << "\n" << std::endl;
    for(auto k = playerMF.begin() ; k != playerMF.end(); k++) k->show();
    
    //ミッドフィルダーをランダムに3人選ぶ
    printf("\n[select MIDFIELDERS:Enter] > ");
    getchar();
    printf("\n");
    srand(static_cast<unsigned int>(time(NULL)));
    std::vector<int> vecMF{ 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    std::mt19937 get_rand_mt(Seed());
    std::shuffle( vecMF.begin(), vecMF.end(), get_rand_mt );
    int mf1=vecMF[0];
    int mf2=vecMF[1];
    int mf3=vecMF[2];
    printf("~selected MF~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    playerMF[mf1].show();
    playerMF[mf2].show();
    playerMF[mf3].show();
    printf("-------------------------------------------------------\n");
}

//フォワードの情報を登録・表示し，ランダムに3人を選ぶ関数
void LFC_FW() {
    std::vector<LFC_Player> playerFW;
    
    //フォワードの情報を登録
    std::ifstream infile("lfc_fw.txt");
    int numfw;
    std::string positionfw;
    std::string namefw;
    
    while (infile >> positionfw >> numfw >> namefw) {
        playerFW.emplace_back();
        playerFW[playerFW.size() -1].setNum(numfw);
        playerFW[playerFW.size() -1].setPosition(positionfw);
        playerFW[playerFW.size() -1].setName(namefw);
    }
    infile.close();
    
    //フォワードの一覧を表示
    printf("[check FORWARDS:Enter] > ");
    getchar();
    printf("\n");
    std::cout << "-FORWARDS----------------------------------------------" << "\n" << std::endl;
    for(auto l = playerFW.begin() ; l != playerFW.end(); l++) l->show();
    
    //フォワードをランダムに3人選ぶ
    printf("\n[select FORWARDS:Enter] > ");
    getchar();
    printf("\n");
    srand(static_cast<unsigned int>(time(NULL)));
    std::vector<int> vecFW{ 0, 1, 2, 3, 4, 5, 6, 7 };
    std::mt19937 get_rand_mt(Seed());
    std::shuffle( vecFW.begin(), vecFW.end(), get_rand_mt );
    int fw1=vecFW[0];
    int fw2=vecFW[1];
    int fw3=vecFW[2];
    printf("~selected FW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    playerFW[fw1].show();
    playerFW[fw2].show();
    playerFW[fw3].show();
    printf("-------------------------------------------------------\n");
}

int main(){
    srand(static_cast<unsigned int>(time(NULL)));
    std::cout << "~~~Liverpool Football Club - team creation program~~~" << "\n\n\n";
    printf("Create a team randomly.  [start:Enter] > ");
    getchar();
    printf("\n\n");
    LFC_GK();
    std::cout << "\n\n";
    LFC_DF();
    std::cout << "\n\n";
    LFC_MF();
    std::cout << "\n\n";
    LFC_FW();
    printf("\n\n");
    printf("Team created.  [FINISH:Enter] > ");
    getchar();
    printf("\n");

    return 0;
}
