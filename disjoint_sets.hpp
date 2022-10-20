class DisjointSet {
private:
    int* rank, * parent, elemsNum;

public:
    DisjointSet(int elemsNum) {
        this->rank = new int[elemsNum];
        this->parent = new int[elemsNum];
        this->elemsNum = elemsNum;

        makeSet();
    }

    void makeSet() {
        for (int i = 0; i < this->elemsNum; i++) {
            this->parent[i] = i;
            this->rank[i] = 0;
        }
    }

    int findItem(int item) {
        if (this->parent[item] == item) return item;

        this->parent[item] = findItem(this->parent[item]);

        return this->parent[item];

    }

    void unionItems(int firstItem, int secItem) {
        int firstItemRep = this->findItem(firstItem);
        int secItemRep = this->findItem(secItem);

        if (firstItemRep == secItemRep) return;

        if (this->rank[firstItemRep] == this->rank[secItemRep]) {
            this->parent[secItemRep] = firstItemRep;
            this->rank[firstItemRep] += 1;
        }
        else if (this->rank[firstItemRep] > this->rank[secItemRep]) {
            this->parent[secItemRep] = firstItemRep;
        }
        else if (this->rank[firstItemRep] < this->rank[secItemRep]) {
            this->parent[firstItemRep] = secItemRep;
        }
    }
};
