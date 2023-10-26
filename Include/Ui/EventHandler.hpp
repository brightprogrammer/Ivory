#ifndef IVORY_EVENT_HANDLER_HPP
#define IVORY_EVENT_HANDLER_HPP

#include <vector>

#include <SFML/System/Vector2.hpp>

/**
 * An event handler is an abstract class that provides
 * the event handling mechanism to a class and it's members.
 *
 * This will create a tree structure of all event handlers.
 * An object can register multiple event handlers to itself.
 * The events will travel down the event tree.
 *
 * If any child processes the event then event is not handled
 * any further, but, if none of the child event handlers handle
 * the generated event then parent must handle it, or leave the
 * handling to it's own parent!
 *
 * This way, any unhandled event first travels down the tree
 * and then up the event handling tree!
 * */
class EventHandler {
    public:
        /**
         * Check if this event handler was interacted with.
         *
         * @param pos Click position
         * @return true if this handler was clicked, false otherwise.
         * All derived classes MUST implement this method as this is
         * a purely virtual method!
         * */
        virtual bool IsClicked(const sf::Vector2i& pos) = 0;

        /**
         * Process the click event. This MUST be implemented by
         * parent event.
         *
         * @param pos Click positiion.
         * @return true if the event was handled properly, false otherwise.
         * */
        virtual bool OnClick(const sf::Vector2i& pos) = 0;

        /**
         * Dispatch given event to all child event handlers.
         * This is the part where events first go down the tree to be handled,
         * and then bubble up backwards.
         *
         * @param pos Position of click.
         * @return true if event was handled by any of the children, false otherwise
         * */
        inline bool DispatchEventToChildren(const sf::Vector2i& pos) {
            /* if for any of child handler, it is clicked and event is handled, then return true */
            for(auto handler : m_handlers) {
                if(handler->IsClicked(pos) && handler->OnClick(pos)) {
                    return true;
                }
            }

            /* false otherwise */
            return false;
        }

        /**
         * Add an event handler child to this event  handler.
         * Any received event will be propagated child event
         * handlers first. If any of the event handlers return
         * true in @c OnClick() method then this will return
         * assuming that the event was taken care of.
         *
         * In any other case, the event is handled by this event
         * handler! This gives rise to an event handling tree.
         * */
        inline void AddChild(EventHandler& ehandler) {
            m_handlers.push_back(&ehandler);
        }
    private:
        std::vector<EventHandler*> m_handlers; /* children event handlers */
};

#endif // IVORY_EVENT_HANDLER_HPP
