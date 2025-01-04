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

3. **Validation**  
   - Validates starting tags, closing tags, attributes, inline styles, external CSS, and content.
   - Provides detailed error messages for invalid syntax or mismatched tags.

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
      |_> Transition Table.xlsx # Transition-Table of DFA
      |_> testing.txt           # Input file to test Soft-coded lexical analyzer
      |_> input.txt             # Input file to test Hard-coded lexical analyzer


---

## How to Use

### Prerequisites
- **C++ Compiler** (e.g., GCC or Clang)
- **JFLAP** (optional, for visualizing the DFA)

### Running the Lexical Analyzer
1. Navigate to the `Lexical Analyzer/` directory.
2. To run the **hard-coded lexical analyzer**:
   ```bash
   g++ HardCoded.cpp -o HardCoded
   ./HardCoded
   ```
3. To run the **soft-coded lexical analyzer**:
   ```bash
   g++ SoftCoded.cpp -o SoftCoded
   ./SoftCoded
   ```

### Running the Syntax Analyzer
1. Navigate to the `Syntax Analyzer/` directory.
2. Compile and run the syntax analyzer:
   ```bash
   g++ SyntaxAnalyzer.cpp -o SyntaxAnalyzer
   ./SyntaxAnalyzer
   ```

### Input Files
- Provide test HTML snippets as input to the lexical analyzer or syntax analyzer.
- CFG rules are stored in `Syntax Analyzer/CFG.txt` and loaded by the syntax analyzer.

---

## DFA and CFG

### DFA
- **File:** `Lexical Analyzer/DFA.pdf`  
  The DFA diagram visually represents the states and transitions for recognizing valid tokens.  

- **File:** `Lexical Analyzer/DFA.jff`  
  Open this file with JFLAP to interactively test and visualize the DFA.

### CFG
- **File:** `Syntax Analyzer/CFG.txt`  
  The CFG defines the grammar rules for parsing HTML structure, including:
  - Starting and closing tags.
  - Attributes and properties.
  - Content validation.

---

## Contribution Guidelines
1. Fork the repository and create a new branch.
2. Make your changes and submit a pull request.
3. Include test cases for new functionality.

---

## Author
**H. Waleed Khalid**  
Feel free to reach out for feedback or collaboration opportunities.