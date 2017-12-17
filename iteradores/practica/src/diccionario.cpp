Diccionario Diccionario::ObtainPalabrasconDeficionContiene(string key){
  Diccionario aux;
  iterator ite;
  for(ite=begin();ite!=end();++ite){
    for(int i = 0;i<int((*ite).second.size());i++){
      if ((*ite).second[i].find(key) != std::string::npos) {
        aux.set((*ite).first,(*ite).second[i]);
      }
    }
  }
  return aux;
}
