#ifndef PR
#define PR(a, n)         \
  {                      \
    cout << #a << " = "; \
    FR(i, n)             \
    cout << a[i] << ' '; \
    cout << endl;        \
  }
#endif

#ifndef FF
#define FF(i, begin, end)                             \
  for (__typeof(end) i = (begin) - ((begin) > (end)); \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#endif

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

// string
template <typename T, typename... Args>
void error(istream_iterator<string> it, const string &a, Args... args);

// vector<T>
template <typename T, typename... Args>
void error(istream_iterator<string> it, vector<T> &a, Args... args) {
  cout << *it << " = [";
  for (const auto &x : a) cout << " " << x;
  cout << " ]" << endl;
  error(++it, args...);
}

// set<T>
template <typename T, typename... Args>
void error(istream_iterator<string> it, set<T> &a, Args... args) {
  cout << *it << " = {";
  for (const auto &x : a) cout << " " << x;
  cout << " }" << endl;
  error(++it, args...);
}

// T
template <typename T, typename... Args>
void error(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << endl;
  error(++it, args...);
}

// empty
void error(istream_iterator<string> it) {
  cout << endl;
  return;
}

template <typename T, typename... Args>
void error(istream_iterator<string> it, const string &a, Args... args) {
  cout << a << endl;
  error(++it, args...);
}
