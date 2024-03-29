//
//  Copyright (C) 2014-2024 CASM Organization <https://casm-lang.org>
//  All rights reserved.
//
//  Developed by: Philipp Paulweber et al.
//  <https://github.com/casm-lang/libstdhl/graphs/contributors>
//
//  This file is part of libstdhl.
//
//  libstdhl is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  libstdhl is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with libstdhl. If not, see <http://www.gnu.org/licenses/>.
//
//  Additional permission under GNU GPL version 3 section 7
//
//  libstdhl is distributed under the terms of the GNU General Public License
//  with the following clarification and special exception: Linking libstdhl
//  statically or dynamically with other modules is making a combined work
//  based on libstdhl. Thus, the terms and conditions of the GNU General
//  Public License cover the whole combination. As a special exception,
//  the copyright holders of libstdhl give you permission to link libstdhl
//  with independent modules to produce an executable, regardless of the
//  license terms of these independent modules, and to copy and distribute
//  the resulting executable under terms of your choice, provided that you
//  also meet, for each linked independent module, the terms and conditions
//  of the license of that module. An independent module is a module which
//  is not derived from or based on libstdhl. If you modify libstdhl, you
//  may extend this exception to your version of the library, but you are
//  not obliged to do so. If you do not wish to do so, delete this exception
//  statement from your version.
//

#pragma once
#ifndef _LIBSTDHL_CPP_NETWORK_LSP_IDENTIFIER_H_
#define _LIBSTDHL_CPP_NETWORK_LSP_IDENTIFIER_H_

/**
   @brief    TBD

   TBD

   https://github.com/Microsoft/language-server-protocol/blob/master/protocol.md
*/

namespace libstdhl
{
    namespace Network
    {
        namespace LSP
        {
            namespace Identifier
            {
                // A
                constexpr const char* actions = "actions";

                constexpr const char* activeParameter = "activeParameter";

                constexpr const char* activeSignature = "activeSignature";

                constexpr const char* added = "added";

                constexpr const char* additionalTextEdits = "additionalTextEdits";

                constexpr const char* alpha = "alpha";

                constexpr const char* arguments = "arguments";

                constexpr const char* applied = "applied";

                constexpr const char* applyEdit = "applyEdit";

                // B

                constexpr const char* blue = "blue";

                // C

                constexpr const char* cancelRequest = "$/cancelRequest";

                constexpr const char* capabilities = "capabilities";

                constexpr const char* ch = "ch";

                constexpr const char* change = "change";

                constexpr const char* changeNotifications = "changeNotifications";

                constexpr const char* changes = "changes";

                constexpr const char* character = "character";

                constexpr const char* children = "children";

                constexpr const char* client_registerCapability = "client/registerCapability";

                constexpr const char* client_unregisterCapability = "client/unregisterCapability";

                constexpr const char* code = "code";

                constexpr const char* codeAction = "codeAction";

                constexpr const char* codeActionKinds = "codeActionKinds";

                constexpr const char* codeActionProvider = "codeActionProvider";

                constexpr const char* codeLens = "codeLens";

                constexpr const char* codeLens_resolve = "codeLens/resolve";

                constexpr const char* codeLensProvider = "codeLensProvider";

                constexpr const char* color = "color";

                constexpr const char* colorProvider = "colorProvider";

                constexpr const char* command = "command";

                constexpr const char* commands = "commands";

                constexpr const char* comment = "comment";

                constexpr const char* commitCharacters = "commitCharacters";

                constexpr const char* completion = "completion";

                constexpr const char* completionItem = "completionItem";

                constexpr const char* completionItem_resolve = "completionItem/resolve";

                constexpr const char* completionProvider = "completionProvider";

                constexpr const char* configuration = "configuration";

                constexpr const char* containerName = "containerName";

                constexpr const char* contentChanges = "contentChanges";

                constexpr const char* contents = "contents";

                constexpr const char* context = "context";

                constexpr const char* create = "create";

                // D

                constexpr const char* data = "data";

                constexpr const char* definition = "definition";

                constexpr const char* definitionProvider = "definitionProvider";

                constexpr const char* deletion = "delete";

                constexpr const char* deprecated = "deprecated";

                constexpr const char* detail = "detail";

                constexpr const char* diagnostics = "diagnostics";

                constexpr const char* didChangeConfiguration = "didChangeConfiguration";

                constexpr const char* didChangeWatchedFiles = "didChangeWatchedFiles";

                constexpr const char* didSave = "didSave";

                constexpr const char* documentation = "documentation";

                constexpr const char* documentChanges = "documentChanges";

                constexpr const char* documentFormattingProvider = "documentFormattingProvider";

                constexpr const char* documentHighlight = "documentHighlight";

                constexpr const char* documentHighlightProvider = "documentHighlightProvider";

                constexpr const char* documentLink = "documentLink";

                constexpr const char* documentLinkProvider = "documentLinkProvider";

                constexpr const char* documentLink_resolve = "documentLink/resolve";

                constexpr const char* documentOnTypeFormattingProvider =
                    "documentOnTypeFormattingProvider";

                constexpr const char* documentRangeFormattingProvider =
                    "documentRangeFormattingProvider";

                constexpr const char* documentSelector = "documentSelector";

                constexpr const char* documentSymbol = "documentSymbol";

                constexpr const char* documentSymbolProvider = "documentSymbolProvider";

                constexpr const char* dynamicRegistration = "dynamicRegistration";

                // E

                constexpr const char* edit = "edit";

                constexpr const char* edits = "edits";

                constexpr const char* end = "end";

                constexpr const char* endCharacter = "endCharacter";

                constexpr const char* endLine = "endLine";

                constexpr const char* error = "error";

                constexpr const char* event = "event";

                constexpr const char* executeCommand = "executeCommand";

                constexpr const char* executeCommandProvider = "executeCommandProvider";

                constexpr const char* exit = "exit";

                constexpr const char* experimental = "experimental";

                // F

                constexpr const char* firstTriggerCharacter = "firstTriggerCharacter";

                constexpr const char* filterText = "filterText";

                constexpr const char* foldingRangeProvider = "foldingRangeProvider";

                constexpr const char* formatting = "formatting";

                // G

                constexpr const char* green = "green";

                constexpr const char* globPattern = "globPattern";

                // H

                constexpr const char* hover = "hover";

                constexpr const char* hoverProvider = "hoverProvider";

                // I

                constexpr const char* id = "id";

                constexpr const char* ignoreIfExists = "ignoreIfExists";

                constexpr const char* imports = "imports";

                constexpr const char* implementationProvider = "implementationProvider";

                constexpr const char* includeDeclaration = "includeDeclaration";

                constexpr const char* includeText = "includeText";

                constexpr const char* initializationOptions = "initializationOptions";

                constexpr const char* initialize = "initialize";

                constexpr const char* initialized = "initialized";

                constexpr const char* insertSpaces = "insertSpaces";

                constexpr const char* insertText = "insertText";

                constexpr const char* insertTextFormat = "insertTextFormat";

                constexpr const char* items = "items";

                constexpr const char* isIncomplete = "isIncomplete";

                // J

                constexpr const char* jsonrpc = "jsonrpc";

                constexpr const char* jsonrpc_version = "2.0";

                // K

                constexpr const char* kind = "kind";

                // L

                constexpr const char* label = "label";

                constexpr const char* language = "language";

                constexpr const char* languageId = "languageId";

                constexpr const char* line = "line";

                constexpr const char* location = "location";

                // M
                constexpr const char* markdown = "markdown";

                constexpr const char* message = "message";

                constexpr const char* method = "method";

                constexpr const char* moreTriggerCharacter = "moreTriggerCharacter";

                // N

                constexpr const char* name = "name";

                constexpr const char* newName = "newName";

                constexpr const char* newText = "newText";

                constexpr const char* newUri = "newUri";

                // O

                constexpr const char* oldUri = "oldUri";

                constexpr const char* onTypeFormatting = "onTypeFormatting";

                constexpr const char* openClose = "openClose";

                constexpr const char* options = "options";

                constexpr const char* originSelectionRange = "originSelectionRange";

                constexpr const char* overwrite = "overwrite";

                // P

                constexpr const char* parameters = "parameters";

                constexpr const char* params = "params";

                constexpr const char* pattern = "pattern";

                constexpr const char* placeholder = "placeholder";

                constexpr const char* plaintext = "plaintext";

                constexpr const char* position = "position";

                constexpr const char* prepareProvider = "prepareProvider";

                constexpr const char* preselect = "preselect";

                constexpr const char* processId = "processId";

                // Q

                constexpr const char* quickfix = "quickfix";

                constexpr const char* query = "query";

                // R

                constexpr const char* range = "range";

                constexpr const char* rangeFormatting = "rangeFormatting";

                constexpr const char* rangeLength = "rangeLength";

                constexpr const char* reason = "reason";

                constexpr const char* recursive = "recursive";

                constexpr const char* red = "red";

                constexpr const char* refactor = "refactor";

                constexpr const char* refactorExtract = "refactor.extract";

                constexpr const char* refactorInline = "refactor.inline";

                constexpr const char* refactorRewrite = "refactor.rewrite";

                constexpr const char* references = "references";

                constexpr const char* region = "region";

                constexpr const char* registerOptions = "registerOptions";

                constexpr const char* registrations = "registrations";

                constexpr const char* referencesProvider = "referencesProvider";

                constexpr const char* removed = "removed";

                constexpr const char* rename = "rename";

                constexpr const char* renameProvider = "renameProvider";

                constexpr const char* resolveProvider = "resolveProvider";

                constexpr const char* result = "result";

                constexpr const char* retry = "retry";

                constexpr const char* rootUri = "rootUri";

                // S

                constexpr const char* save = "save";

                constexpr const char* scheme = "scheme";

                constexpr const char* scopeUri = "scopeUri";

                constexpr const char* section = "section";

                constexpr const char* selectionRange = "selectionRange";

                constexpr const char* settings = "settings";

                constexpr const char* severity = "severity";

                constexpr const char* shutdown = "shutdown";

                constexpr const char* signatureHelp = "signatureHelp";

                constexpr const char* signatureHelpProvider = "signatureHelpProvider";

                constexpr const char* signatures = "signatures";

                constexpr const char* snippetSupport = "snippetSupport";

                constexpr const char* source = "source";

                constexpr const char* sourceOrganizeImports = "source.organizeImports";

                constexpr const char* sortText = "sortText";

                constexpr const char* start = "start";

                constexpr const char* startLine = "startLine";

                constexpr const char* startCharacter = "startCharacter";

                constexpr const char* supported = "supported";

                constexpr const char* symbol = "symbol";

                constexpr const char* symbolInformation = "symbolInformation";

                constexpr const char* synchronization = "synchronization";

                // T

                constexpr const char* tabSize = "tabSize";

                constexpr const char* target = "target";

                constexpr const char* targetRange = "targetRange";

                constexpr const char* targetSelectionRange = "targetSelectionRange";

                constexpr const char* targetUri = "targetUri";

                constexpr const char* telemetry_event = "telemetry/event";

                constexpr const char* text = "text";

                constexpr const char* textDocument = "textDocument";

                constexpr const char* textDocumentSync = "textDocumentSync";

                constexpr const char* textDocument_codeAction = "textDocument/codeAction";

                constexpr const char* textDocument_codeLens = "textDocument/codeLens";

                constexpr const char* textDocument_colorPresentation =
                    "textDocument/colorPresentation";

                constexpr const char* textDocument_completion = "textDocument/completion";

                constexpr const char* textDocument_definition = "textDocument/definition";

                constexpr const char* textDocument_didChange = "textDocument/didChange";

                constexpr const char* textDocument_didClose = "textDocument/didClose";

                constexpr const char* textDocument_didOpen = "textDocument/didOpen";

                constexpr const char* textDocument_didSave = "textDocument/didSave";

                constexpr const char* textDocument_documentColor = "textDocument/documentColor";

                constexpr const char* textDocument_documentHighlight =
                    "textDocument/documentHighlight";

                constexpr const char* textDocument_documentLink = "textDocument/documentLink";

                constexpr const char* textDocument_documentSymbol = "textDocument/documentSymbol";

                constexpr const char* textDocument_foldingRange = "textDocument/foldingRange";

                constexpr const char* textDocument_formatting = "textDocument/formatting";

                constexpr const char* textDocument_hover = "textDocument/hover";

                constexpr const char* textDocument_implementation = "textDocument/implementation";

                constexpr const char* textDocument_onTypeFormatting =
                    "textDocument/onTypeFormatting";

                constexpr const char* textDocument_prepareRename = "textDocument/prepareRename";

                constexpr const char* textDocument_publishDiagnostics =
                    "textDocument/publishDiagnostics";

                constexpr const char* textDocument_rangeFormatting = "textDocument/rangeFormatting";

                constexpr const char* textDocument_references = "textDocument/references";

                constexpr const char* textDocument_rename = "textDocument/rename";

                constexpr const char* textDocument_signatureHelp = "textDocument/signatureHelp";

                constexpr const char* textDocument_typeDefinition = "textDocument/typeDefinition";

                constexpr const char* textDocument_willSave = "textDocument/willSave";

                constexpr const char* textDocument_willSaveWaitUntil =
                    "textDocument/willSaveWaitUntil";

                constexpr const char* textEdit = "textEdit";

                constexpr const char* title = "title";

                constexpr const char* trace = "trace";

                constexpr const char* triggerCharacters = "triggerCharacters";

                constexpr const char* triggerCharacter = "triggerCharacter";

                constexpr const char* triggerKind = "triggerKind";

                constexpr const char* type = "type";

                constexpr const char* typeDefinitionProvider = "typeDefinitionProvider";

                // U

                constexpr const char* uri = "uri";

                constexpr const char* unregistrations = "unregistrations";

                // V

                constexpr const char* value = "value";

                constexpr const char* version = "version";

                // W

                constexpr const char* watchers = "watchers";

                constexpr const char* willSave = "willSave";

                constexpr const char* willSaveWaitUntil = "willSaveWaitUntil";

                constexpr const char* window_logMessage = "window/logMessage";

                constexpr const char* window_showMessage = "window/showMessage";

                constexpr const char* window_showMessageRequest = "window/showMessageRequest";

                constexpr const char* workspace = "workspace";

                constexpr const char* workspace_applyEdit = "workspace/applyEdit";

                constexpr const char* workspace_configuration = "workspace/configuration";

                constexpr const char* workspace_didChangeWorkspaceFolders =
                    "workspace/didChangeWorkspaceFolders";

                constexpr const char* workspace_didChangeConfiguration =
                    "workspace/didChangeConfiguration";

                constexpr const char* workspace_didChangeWatchedFiles =
                    "workspace/didChangeWatchedFiles";

                constexpr const char* workspace_executeCommand = "workspace/executeCommand";

                constexpr const char* workspace_symbol = "workspace/symbol";

                constexpr const char* workspace_workspaceFolders = "workspace/workspaceFolders";

                constexpr const char* workspaceEdit = "workspaceEdit";

                constexpr const char* workspaceFolders = "workspaceFolders";

                constexpr const char* workspaceSymbolProvider = "workspaceSymbolProvider";

                // X

                // Y

                // Z
            }
        }
    }
}

#endif  // _LIBSTDHL_CPP_NETWORK_LSP_IDENTIFIER_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//
