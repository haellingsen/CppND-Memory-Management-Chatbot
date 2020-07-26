#ifndef CHATLOGIC_H_
#define CHATLOGIC_H_

#include <vector>
#include <string>
#include "chatgui.h"

// forward declarations
class ChatBot;
class GraphEdge;
class GraphNode;


/* Task 4 : Moving Smart Pointers

DONE 1: In files chatlogic.h / chatlogic.cpp and graphnodes.h / graphnodes.cpp
change the ownership of all instances of GraphEdge in a way such that each
instance of GraphNode exclusively owns the outgoing GraphEdges and holds
non-owning references to incoming GraphEdges.

DONE 2: Use appropriate smart pointers and where required, make changes to the
code such that data structures and function parameters reflect the changes.

DONE 3: When transferring ownership from class ChatLogic,
where all instances of GraphEdge are created, into instances of GraphNode, make
sure to use move semantics.
 */

class ChatLogic
{
private:
    //// STUDENT CODE
    ////

    // data handles (owned)
    std::vector<std::unique_ptr<GraphNode>> _nodes;
    std::vector<GraphEdge *> _edges;

    ////
    //// EOF STUDENT CODE

    // data handles (not owned)
    GraphNode *_currentNode;
    ChatBot *_chatBot;
    ChatBotPanelDialog *_panelDialog;

    // proprietary type definitions
    typedef std::vector<std::pair<std::string, std::string>> tokenlist;

    // proprietary functions
    template <typename T>
    void AddAllTokensToElement(std::string tokenID, tokenlist &tokens, T &element);

public:
    // constructor / destructor
    ChatLogic();
    ~ChatLogic();

    // getter / setter
    void SetPanelDialogHandle(ChatBotPanelDialog *panelDialog);
    void SetChatbotHandle(ChatBot *chatbot);

    // proprietary functions
    void LoadAnswerGraphFromFile(std::string filename);
    void SendMessageToChatbot(std::string message);
    void SendMessageToUser(std::string message);
    wxBitmap *GetImageFromChatbot();
};

#endif /* CHATLOGIC_H_ */