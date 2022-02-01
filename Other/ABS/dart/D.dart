import 'dart:convert';
import 'dart:io';

import 'dart:math';

class Reader {
  Stream<String> _lines;
  List<List<String>> _tokens;
  String _delimiter = ' ';
  int _linePointer = 0;
  int _tokenPointer = 0;

  Reader() {
    _tokens = new List<List<String>>();
    _lines = stdin.transform(utf8.decoder).transform(LineSplitter());
  }

  void setDelimiter(String delimiter) {
    this._delimiter = delimiter;
  }

  void init() async {
    await for (String line in _lines) {
      _tokens.add(List<String>());
      for (String token in line.split(_delimiter)) {
        _tokens.last.add(token);
      }
    }
  }

  String _getToken() {
    String ret = _tokens[_linePointer][_tokenPointer];
    _toNextToken();
    return ret;
  }

  void _toNextToken() {
    _tokenPointer++;
    if (_tokenPointer == _tokens[_linePointer].length) {
      _linePointer++;
      _tokenPointer = 0;
    }
  }

  String next() {
    return _getToken();
  }

  String nextString() {
    return _getToken();
  }

  double nextDouble() {
    return double.parse(_getToken());
  }

  int nextInt() {
    return int.parse(_getToken());
  }
}

main() async {
  Reader reader = new Reader();
  await reader.init();

  int n = reader.nextInt();
  int ans = 10000000;
  for (int i = 0; i < n; i++) {
    int a = reader.nextInt();
    int count = 0;
    while (a % 2 == 0) {
      count++;
      a = (a / 2).floor();
    }
    ans = min(ans, count);
  }

  print(ans);
}
