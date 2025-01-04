# HTML Grammar Analyzer

This project implements a comprehensive **Lexical Analyzer** and **Syntax Analyzer** for a simplified HTML grammar. The project is designed to tokenize and parse HTML content using **Deterministic Finite Automaton (DFA)** and **Context-Free Grammar (CFG)**.

---

## Project Overview

### Features
1. **Lexical Analysis**
   - Implements DFA-based token recognition.
   - Two approaches:
     - **Hard-Coded**: Manual rules defined in code.
     - **Soft-Coded**: Flexible rules using ASCII values.
   - Recognizes HTML elements, attributes, properties, and content.

2. **Syntax Analysis**
   - Uses a Context-Free Grammar (CFG) to parse the structure of HTML documents.
   - Validates tag hierarchy, attributes, and content.

---

## Repository Structure

```plaintext
HTML-Grammar-Analyzer/
|- Syntax Analyzer/
      |_> SyntaxAnalyzer.cpp    # Syntax analyzer implementation
      |_> CFG.txt               # CFG rules for parsing
|- Lexical Analyzer/
      |_> DFA.pdf               # Diagram of DFA
      |_> DFA.jff               # DFA file (for JFLAP)
      |_> HardCoded.cpp         # Hard-coded lexical analyzer
      |_> SoftCoded.cpp         # Soft-coded lexical analyzer
