
#ifndef FR
#define FR(i, n) for (int i = 0; i < (n); ++i)
#endif

// Call this, pass whatever, implement 'error' for new container types
#define DB(args...)                          \
  {                                          \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    error(_it, args);                        \
  }

// DEFINITIONS -----------------------------

// vector<T>
template <typename T, typename... Args>
void error(istream_iterator<string> it, vector<T> &a, Args... args);

// set<T>
template <typename T, typename... Args>
void error(istream_iterator<string> it, set<T> &a, Args... args);

// T
template <typename T, typename... Args>
void error(istream_iterator<string> it, T a, Args... args);

// empty
void error(istream_iterator<string> it);

// vector<T>
template <typename T, typename... Args>
void error(istream_iterator<string> it, vector<T> &a, Args... args) {
  cerr << *it << " = [";
  for (const auto &x : a) cerr << " " << x;
  cerr << " ]" << endl;
  error(++it, args...);
}

// set<T>
template <typename T, typename... Args>
void error(istream_iterator<string> it, set<T> &a, Args... args) {
  cerr << *it << " = {";
  for (const auto &x : a) cerr << " " << x;
  cerr << " }" << endl;
  error(++it, args...);
}

// T
template <typename T, typename... Args>
void error(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  error(++it, args...);
}

// empty
void error(istream_iterator<string> it) {
}