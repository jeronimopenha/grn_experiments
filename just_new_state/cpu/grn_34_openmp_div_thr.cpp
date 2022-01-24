/*
 * This code was wrote to solve a well defined problems with GRN where the parameters were:
 * 1 - Number of nodes: - 24
 * 2 - The names of the nodes are in defines.h (They were read from the grn expressions file)
 * 3 - The code will find the next state for each initial state between 0x000000000 and 0x3ffffffff
 * 4 - It will use multi-core system with the available number of threads of the running system
 */

#include <iostream>
#include <bits/stdc++.h>
#include "defines.h"

#define NUM_NOS 2

using namespace std;

void grnPass(bitset<NUM_NOS> *grn){
    bitset<NUM_NOS> aux;
    aux = (*grn);
    aux[0] = 0;
    cout << (*grn) << endl;
    cout << aux << endl;
    (*grn)[1] = 0;
    cout << (*grn) << endl;

    /*
    grn[Squaline] = (aux[Farnesyl_pyrophosphate]);
    grn[Lanosterol] = (aux[Squaline]);
    grn[Acetyl_CoA] = (aux[Acetyl_CoA]);
    grn[HMG_CoA_Reductase_RNA] = (aux[HMG_CoA_Reductase_gene]);
    grn[Cyp51_RNA] = (aux[Cyp51_gene]);
    grn[Septdehydrocholesterol] = (aux[Lanosterol]);
    grn[Insig_SREBP_SCAP] =  ~ ((aux[Cholesterol]));
    grn[FPP_Synthase_gene] = (aux[mSREBP]) ;
    grn[HMG_CoA_Reductase_gene] = (aux[mSREBP]) ;
    grn[Acetyl_CoA_acetyltransferase_RNA] = (aux[Acetyl_CoA_acetyltransferase_gene]) ;
    grn[Statins] = (aux[Statins]) ;
    grn[Acetyl_CoA_acetyltransferase_gene] = (aux[mSREBP]) ;
    grn[Desmosterol] = (aux[Lanosterol]) ;
    grn[Mevalonic_Acid] = (aux[HMG_CoA] & (((aux[HMG_CoA_Reductase])))) ;
    grn[Acetoacetyl_CoA] = (aux[Acetyl_CoA] & (((aux[Acetyl_CoA_acetyltransferase])))) ;
    grn[Mevalonyl_pyrophosphate] = (aux[Mevalonic_Acid]);
    grn[HMG_CoA] = (aux[Acetoacetyl_CoA] & (((aux[Acetyl_CoA] & aux[HMG_CoA_Synthase])))) ;
    grn[Dimethyl_allyl_pyrophosphate] = (aux[Isopentenyl_pyrophosphate]) ;
    grn[HMG_CoA_Reductase]= ((aux[HMG_CoA_Reductase_RNA]) & ~ (aux[Statins])) ;
    grn[FPP_Synthase] = (aux[FPP_Synthase_RNA]) ;
    grn[HMG_CoA_Synthase_RNA] = (aux[HMG_CoA_Synthase_gene]) ;
    grn[SREBP_SCAP] = ((aux[Insig_SREBP_SCAP]) & ~ (aux[Statins])) ;
    grn[Geranyl_pyrophosphate] = (aux[Dimethyl_allyl_pyrophosphate])  | (aux[Isopentenyl_pyrophosphate]) ;
    grn[Cyp51] = (aux[Cyp51_RNA]) ;
    grn[Isopentenyl_pyrophosphate] = (aux[Mevalonyl_pyrophosphate]) ;
    grn[Acetyl_CoA_acetyltransferase] = (aux[Acetyl_CoA_acetyltransferase_RNA]) ;
    grn[Farnesyl_pyrophosphate] = ((aux[Geranyl_pyrophosphate]) & ~ (aux[FPP_Synthase])) ;
    grn[mSREBP] = (aux[pSREBP]);
    grn[FPP_Synthase_RNA] = (aux[FPP_Synthase_gene]) ;
    grn[pSREBP] = (aux[SREBP_SCAP]) ;
    grn[HMG_CoA_Synthase_gene] = (aux[mSREBP]) ;
    grn[Cyp51_gene] = (aux[mSREBP]) ;
    grn[Cholesterol] = (aux[Desmosterol])  | (aux[Septdehydrocholesterol]) ;
    grn[HMG_CoA_Synthase] = (aux[HMG_CoA_Synthase_RNA]) ;
    */
}

int main(){

    // default constructor initializes with all bits 0
    bitset<NUM_NOS> grn(15);


    for (bitset <NUM_NOS> i (0); i.any() ; i = i + 1 )

    //grnPass(&grn);

    //cout << grn << endl;


    /*
     * /*
 * This function adds 1 to the bitset.
 *
 * Since the bitset does not natively support addition we do it manually.
 * If XOR a bit with 1 leaves it as one then we did not overflow so we can break out
 * otherwise the bit is zero meaning it was previously one which means we have a bit
 * overflow which must be added 1 to the next bit etc.
 *
void increment(boost::dynamic_bitset<>& bitset)
{
    for(int loop = 0;loop < bitset.count(); ++loop)
    {
        if ((bitset[loop] ^= 0x1) == 0x1)
        {    break;
        }
    }
}
     *
    // bset2 is initialized with bits of 20
    bitset<NUM_NOS> bset2(20);

    // bset3 is initialized with bits of specified binary string
    bitset<NUM_NOS> bset3(string("1100"));

    // cout prints exact bits representation of bitset
    cout << bset1 << endl; // 00000000000000000000000000000000
    cout << bset2 << endl; // 00000000000000000000000000010100
    cout << bset3 << endl; // 00000000000000000000000000001100
    cout << endl;

    // declaring set8 with capacity of 8 bits

    bitset<8> set8; // 00000000

    // setting first bit (or 6th index)
    set8[1] = 1; // 00000010
    set8[4] = set8[1]; // 00010010
    cout << set8 << endl;

    // count function returns number of set bits in bitset
    int numberof1 = set8.count();

    // size function returns total number of bits in bitset
    // so there difference will give us number of unset(0)
    // bits in bitset
    int numberof0 = set8.size() - numberof1;

    cout << set8 << " has " << numberof1 << " ones and "
         << numberof0 << " zeros\n";

    // test function return 1 if bit is set else returns 0
    cout << "bool representation of " << set8 << " : ";
    for (int i = 0; i < set8.size(); i++)
        cout << set8.test(i) << " ";

    cout << endl;

    // any function returns true, if atleast 1 bit
    // is set
    if (!set8.any())
        cout << "set8 has no bit set.\n";

    if (!bset1.any())
        cout << "bset1 has no bit set.\n";

    // none function returns true, if none of the bit
    // is set
    if (!bset1.none())
        cout << "bset1 has some bit set\n";

    // bset.set() sets all bits
    cout << set8.set() << endl;

    // bset.set(pos, b) makes bset[pos] = b
    cout << set8.set(4, 0) << endl;

    // bset.set(pos) makes bset[pos] = 1  i.e. default
    // is 1
    cout << set8.set(4) << endl;

    // reset function makes all bits 0
    cout << set8.reset(2) << endl;
    cout << set8.reset() << endl;

    // flip function flips all bits i.e.  1 <-> 0
    // and  0 <-> 1
    cout << set8.flip(2) << endl;
    cout << set8.flip() << endl;

    // Converting decimal number to binary by using bitset
    int num = 100;
    cout << "\nDecimal number: " << num
         << "  Binary equivalent: " << bitset<8>(num);
    */
    return 0;
}

//void pass(){

//}


/*
int main(int argc, char **argv) {
    InputParser input(argc, argv);

    string filein = input.getCmdOption("-i");
    string fileout = input.getCmdOption("-o");

    if(!filein.size() || !fileout.size()) {
        cout << "Usage: ./<executable> -i <input filename> -o <utput filename csv>" << endl;
        exit(255);
    }

    uint32_t **period_vet;
    uint32_t **transient_vet;
    uint64_t *init_state;
    uint64_t *end_state;
    uint32_t lines;

    bool **s0;
    bool **s1;

    uint64_t **atractor_vet;

    readInputFile(&period_vet, &transient_vet, &init_state, &end_state, &s0, &s1, &atractor_vet, &lines, filein);

    if(period_vet == nullptr || transient_vet == nullptr || init_state == nullptr || end_state == nullptr) {
        cout << "Error: malloc failed!" << endl;
        exit(255);
    }

    high_resolution_clock::time_point s;
    duration<double> diff{};
    s = high_resolution_clock::now();

    runGNR(init_state, end_state, period_vet, transient_vet, s0, s1, atractor_vet, lines);

    diff = high_resolution_clock::now() - s;

    // cout << "Number of state: " << NUM_STATES << endl;
    cout << "Execution Time: " << diff.count() * 1000 << "ms" << endl;
    // cout << "State per second: " << (NUM_STATES/diff.count()) << endl;

    writeOutputFile(period_vet, transient_vet, init_state, end_state, atractor_vet, lines, fileout);

    // free(period_vet);
    // free(transient_vet);

    return 0;
}


/*
#include <iostream>
#include <math.h>
#include <omp.h>
#include <chrono>
#include <vector>
#include <algorithm>
#include <fstream>

#define NUM_NOS 34

using namespace std;
using namespace std::chrono;

vector<string> splitString(string s, string delimiter);
void readInputFile(uint32_t ***period, uint32_t ***transient, uint64_t **init_state, uint64_t **end_state, bool ***s0, bool ***s1, uint64_t ***atractor, uint32_t *lines, string filename);
void pass(bool *aux);
bool equals(bool *vet1, bool *vet2);
string vet_to_hex(bool *vet1);
void initialState(uint64_t valor, bool *vet1, bool *vet2);
string boolArraytoString(bool *vet);
uint64_t boolArraytoInt(bool *vet);
void runGNR(uint64_t *init_state, uint64_t *end_state, uint32_t **period_vet, uint32_t **transient_vet, bool **s0, bool **s1, uint64_t **atractor_vet, uint32_t lines);
void writeOutputFile(uint32_t **period, uint32_t **transient, uint64_t *init_state, uint64_t *end_state, uint64_t **atractor, uint32_t lines, string filename);

class InputParser {
private:
    vector<string> tokens;

public:
    InputParser(int &argc, char **argv) {
        for(int i=1; i<argc; ++i) {
            this->tokens.push_back(string(argv[i]));
        }
    }

    bool cmdOptionExists(const string &option) const{
        return find(this->tokens.begin(), this->tokens.end(), option)
                != this->tokens.end();
    }

    const string& getCmdOption(const string &option) const{
        vector<string>::const_iterator itr;
        itr =  find(this->tokens.begin(), this->tokens.end(), option);
        if (itr != this->tokens.end() && ++itr != this->tokens.end() && (*itr).front() != '-'){
            return *itr;
        }
        static const string empty_string("");
        return empty_string;
    }
};

int main(int argc, char **argv) {
    InputParser input(argc, argv);

    string filein = input.getCmdOption("-i");
    string fileout = input.getCmdOption("-o");

    if(!filein.size() || !fileout.size()) {
        cout << "Usage: ./<executable> -i <input filename> -o <utput filename csv>" << endl;
        exit(255);
    }

    uint32_t **period_vet = nullptr;
    uint32_t **transient_vet = nullptr;
    uint64_t *init_state = nullptr;
    uint64_t *end_state = nullptr;
    uint32_t lines;

    bool **s0 = nullptr;
    bool **s1 = nullptr;

    uint64_t **atractor_vet;

    readInputFile(&period_vet, &transient_vet, &init_state, &end_state, &s0, &s1, &atractor_vet, &lines, filein);

    if(period_vet == nullptr || transient_vet == nullptr || init_state == nullptr || end_state == nullptr) {
        cout << "Error: malloc failed!" << endl;
        exit(255);
    }

    high_resolution_clock::time_point s;
    duration<double> diff{};
    s = high_resolution_clock::now();

    runGNR(init_state, end_state, period_vet, transient_vet, s0, s1, atractor_vet, lines);

    diff = high_resolution_clock::now() - s;

    // cout << "Number of state: " << NUM_STATES << endl;
    cout << "Execution Time: " << diff.count() * 1000 << "ms" << endl;
    // cout << "State per second: " << (NUM_STATES/diff.count()) << endl;

    writeOutputFile(period_vet, transient_vet, init_state, end_state, atractor_vet, lines, fileout);

    // free(period_vet);
    // free(transient_vet);

    return 0;
}

void writeOutputFile(uint32_t **period, uint32_t **transient, uint64_t *init_state, uint64_t *end_state, uint64_t **atractor, uint32_t lines, string filename) {
    ofstream file(filename);
    for(uint32_t l=0; l<lines; ++l) {
        for(uint64_t s=init_state[l], i = 0; s <= end_state[l]; ++s, ++i) {
            file << to_string(l) << ", " << to_string(period[l][i]) << ", " << to_string(transient[l][i]) << ", " << std::hex << (atractor[l][i]) << endl;
        }
    }
    file.close();
}

vector<string> splitString(string s, string delimiter) {
    size_t pos = 0;
    vector<string> ans;
    while((pos = s.find(delimiter)) != string::npos) {
        ans.push_back(s.substr(0, pos));
        s.erase(0, pos + delimiter.length());
    }
    ans.push_back(s);
    return ans;
}

void readInputFile(uint32_t ***period, uint32_t ***transient, uint64_t **init_state, uint64_t **end_state, bool ***s0, bool ***s1, uint64_t ***atractor, uint32_t *lines, string filename) {
    ifstream file(filename);
    uint32_t cnt_lines = 0;
    string line;
    uint32_t size;
    vector<vector<string>> all_items;
    while(getline(file, line)) {
        auto items = splitString(line, ",");
        if(items.size() == 4) {
            cnt_lines++;
            all_items.push_back(items);
        }
    }
    file.close();

    (*lines) = cnt_lines;
    (*period) = (uint32_t **) malloc(cnt_lines * sizeof (uint32_t *));
    (*transient) = (uint32_t **) malloc(cnt_lines * sizeof(uint32_t *));
    (*init_state) = (uint64_t *) malloc(cnt_lines * sizeof(uint64_t));
    (*end_state) = (uint64_t *) malloc(cnt_lines * sizeof(uint64_t));
    (*s0) = (bool **) malloc(cnt_lines * sizeof(bool *));
    (*s1) = (bool **) malloc(cnt_lines * sizeof(bool *));
    (*atractor) = (uint64_t **) malloc(cnt_lines * sizeof (uint64_t *));

    for(int i=0; i<cnt_lines; ++i) {
        size = stoul(all_items[i][3], NULL, 10);
        (*period)[i] = (uint32_t *) malloc(size * sizeof(uint32_t));
        (*transient)[i] = (uint32_t *) malloc(size * sizeof(uint32_t));
        (*init_state)[i] = stoull(all_items[i][1], NULL, 16);
        (*end_state)[i] = stoull(all_items[i][2], NULL, 16);
        (*s1)[i] = (bool *) malloc(NUM_NOS * sizeof(bool));
        (*s0)[i] = (bool *) malloc(NUM_NOS * sizeof(bool));
        (*atractor)[i] = (uint64_t *) malloc(size * sizeof(uint64_t));
    }
}

void runGNR(uint64_t *init_state, uint64_t *end_state, uint32_t **period_vet, uint32_t **transient_vet, bool **s0, bool **s1, uint64_t **atractor_vet, uint32_t lines) {
    #pragma omp parallel for schedule(static)
    for(uint32_t l=0; l<lines; ++l) {
        for (uint64_t s = init_state[l], i = 0; s <= end_state[l]; s++, i++) {
            initialState(s, s0[l], s1[l]);
            transient_vet[l][i] = 0;
            period_vet[l][i] = 0;
            do {
                pass(s0[l]);
                pass(s1[l]);
                pass(s1[l]);
                // transient++;
                transient_vet[l][i]++;
            } while (!equals(s0[l], s1[l]));
            do {
                pass(s1[l]);
                // period++;
                period_vet[l][i]++;
            } while (!equals(s0[l], s1[l]));

            period_vet[l][i]--;
            atractor_vet[l][i] = boolArraytoInt(s0[l]);
            // printf("%lld: P: %u T: %u\n", i, period, transient);
            /* if(output.is_open()) {
                string str = "";
                str += to_string()
                str += to_string(i);
                str += ",";
                str += to_string(period);
                str += ",";
                str += to_string(transient);
                str += "\n";
                cout << str << endl;
                output.write(str.c_str(), str.size());
            } *//*
        }
    }
}

void initialState(uint64_t valor, bool *vet1, bool *vet2) {
    for (int i = 0; i < NUM_NOS; i++) {
        vet1[i] = (valor & 1) != 0;
        vet2[i] = vet1[i];
        valor >>= 1;
    }
}

bool equals(bool *vet1, bool *vet2) {
    for (int i = 0; i < NUM_NOS; i++) {
        if (vet1[i] != vet2[i]) {
            return false;
        }
    }
    return true;
}

string vet_to_hex(bool *vet) {
    string hex = "";
    for(int i=0; i<NUM_NOS; i += 4) {
        int v=0;
        for(int j=i+3; j>=i; --j) {
            if(j < NUM_NOS) {
                v = (v << 1) | (vet[j] ? 1 : 0);
            }
        }
        if(v >= 10) hex += ('a' + v - 10);
        else hex += to_string(v);
    }
    reverse(hex.begin(), hex.end());

    return hex;
}

string boolArraytoString(bool *vet) {
    string out = "";
    for (int i = NUM_NOS - 1; i >= 0; i--) {
        if (vet[i]) {
            out += "1";
        } else {
            out += "0";
        }
    }
    return out;
}

uint64_t boolArraytoInt(bool *vet) {
    uint64_t out = 0;
    // std::cout <<"boolArraytoInt:"<< std::endl;
    for (int i = NUM_NOS - 1; i >= 0; i--) {
        //   std::cout << vet[i] << " ";
        out = (out << 1ll) | vet[i];
    }
    //  std::cout << " = " << out << std::endl;
    return out;
}

void pass(bool *aux) {
    bool vet[NUM_NOS];
    for (int i=0; i<NUM_NOS; i++){
        vet[i] = aux[i];
    }
    aux[31]  =   (  vet[11]  )   ;
    aux[25]  =   (  vet[31]  )   ;
    aux[1]  =   (  vet[1]  )   ;
    aux[19]  =   (  vet[18]  )   ;
    aux[8]  =   (  vet[7]  )   ;
    aux[30]  =   (  vet[25]  )   ;
    aux[23]  =   !  (   (  vet[5]  )   )  ;
    aux[13]  =   (  vet[28]  )   ;
    aux[18]  =   (  vet[28]  )   ;
    aux[4]  =   (  vet[3]  )   ;
    aux[33]  =   (  vet[33]  )   ;
    aux[3]  =   (  vet[28]  )   ;
    aux[9]  =   (  vet[25]  )   ;
    aux[26]  =   (  vet[16] &&  (   (   (  vet[17]  )   )   )      )   ;
    aux[0]  =   (  vet[1] &&  (   (   (  vet[2]  )   )   )      )   ;
    aux[27]  =   (  vet[26]  )   ;
    aux[16]  =   (  vet[0] &&  (   (   (  vet[1]  && vet[20]  )   )   )      )   ;
    aux[10]  =   (  vet[24]  )   ;
    aux[17]  =   (   (  vet[19]   )  && !  (  vet[33]   )   )   ;
    aux[12]  =   (  vet[14]  )   ;
    aux[22]  =   (  vet[21]  )   ;
    aux[32]  =   (   (  vet[23]   )  && !  (  vet[33]   )   )   ;
    aux[15]  =   (  vet[10]  )   ||  (  vet[24]  )   ;
    aux[6]  =   (  vet[8]  )   ;
    aux[24]  =   (  vet[27]  )   ;
    aux[2]  =   (  vet[4]  )   ;
    aux[11]  =   (   (  vet[15]   )  && !  (  vet[12]   )   )   ;
    aux[28]  =   (  vet[29]  )   ;
    aux[14]  =   (  vet[13]  )   ;
    aux[29]  =   (  vet[32]  )   ;
    aux[21]  =   (  vet[28]  )   ;
    aux[7]  =   (  vet[28]  )   ;
    aux[5]  =   (  vet[9]  )   ||  (  vet[30]  )   ;
    aux[20]  =   (  vet[22]  )   ;

}
*/
