#include "ElementsMap.h"

template<class K, class V>
void ElementsMap<K,V>::ajouterElement(const K& cle,const V& valeur) {
        elements.insert(pair<K, V>(cle, valeur));
    }
template<class K, class V>
void ElementsMap<K,V>::supprimerElement(K& cle) {
        elements.erase(cle);
    }
template<class K, class V>
V ElementsMap<K,V>::getElement(K& cle){
        auto it = elements.find(cle);
        if (it != elements.end()) {
            return it->second;
        } else {
            throw invalid_argument("Aucun élément pour cette clé.");
        }
    }
template<class K, class V>
vector<V> ElementsMap<K,V>::getElements(){
        vector<V> result;
        for (const auto& it : elements) {
            result.push_back(it.second);
        }
        return result;
    }

