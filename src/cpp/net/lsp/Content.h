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
#ifndef _LIBSTDHL_CPP_NETWORK_LSP_CONTENT_H_
#define _LIBSTDHL_CPP_NETWORK_LSP_CONTENT_H_

#include <libstdhl/Json>
#include <libstdhl/Type>
#include <libstdhl/std/rfc3986>

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
            using Data = libstdhl::Json::Object;

            using DocumentUri = libstdhl::Standard::RFC3986::URI;

            enum class ErrorCode : i32
            {
                // defined by JSON RPC
                ParseError = -32700,
                InvalidRequest = -32600,
                MethodNotFound = -32601,
                InvalidParams = -32602,
                InternalError = -32603,
                serverErrorStart = -32099,
                serverErrorEnd = -32000,
                ServerNotInitialized = -32002,
                UnknownErrorCode = -32001,

                // defined by LSP
                RequestCancelled = -32800,

            };

            class ResponseError final : public Data
            {
              public:
                ResponseError( const Data& data );

                ResponseError( const ErrorCode code, const std::string& message );

                ErrorCode code( void ) const;

                std::string message( void ) const;

                u1 hasData( void ) const;

                Data data( void ) const;

                void setData( const Data& data );

                static void validate( const Data& data );
            };

            namespace TextDocument
            {
                constexpr const std::array< const char*, 3 > EOL = { { "\n", "\r\n", "\r" } };
            }

            class Position : public Data
            {
              public:
                Position( const Data& data );

                Position( const std::size_t line, const std::size_t character );

                std::size_t line( void ) const;

                std::size_t character( void ) const;

                static void validate( const Data& data );
            };

            class Range : public Data
            {
              public:
                Range( const Data& data );

                Range( const Position& start, const Position& end );

                Position start( void ) const;

                Position end( void ) const;

                static void validate( const Data& data );
            };

            class Location : public Data
            {
              public:
                Location( const Data& data );

                Location( const DocumentUri& uri, const Range& range );

                DocumentUri uri( void ) const;

                Range range( void ) const;

                static void validate( const Data& data );
            };

            using Locations = std::vector< Location >;

            enum class DiagnosticSeverity : std::size_t
            {
                Error = 1,
                Warning = 2,
                Information = 3,
                Hint = 4,
            };

            class DiagnosticRelatedInformation : public Data
            {
              public:
                DiagnosticRelatedInformation( const Data& data );

                DiagnosticRelatedInformation(
                    const Location& location, const std::string& message );

                Location location( void ) const;

                std::string message( void ) const;

                static void validate( const Data& data );
            };

            class Diagnostic : public Data
            {
              public:
                Diagnostic( const Data& data );

                Diagnostic( const Range& range, const std::string& message );

                Range range( void ) const;

                std::string message( void ) const;

                u1 hasSeverity( void ) const;

                DiagnosticSeverity severity( void ) const;

                void setSeverity( const DiagnosticSeverity& severity );

                u1 hasCode( void ) const;

                std::string code( void ) const;

                void setCode( const std::string& code );

                void setCode( const std::size_t code );

                u1 hasSource( void ) const;

                std::string source( void ) const;

                void setSource( const std::string& source );

                static void validate( const Data& data );
            };

            class Command : public Data
            {
              public:
                Command( const Data& data );

                Command( const std::string& title, const std::string& command );

                std::string title( void ) const;

                std::string command( void ) const;

                u1 hasArguments( void ) const;

                Data arguments( void ) const;

                void addArgument( const Data& argument );

                static void validate( const Data& data );
            };

            using Commands = std::vector< Command >;

            class TextEdit : public Data
            {
              public:
                TextEdit( const Data& data );

                TextEdit( const Range& range, const std::string& newText );

                Range range( void ) const;

                std::string newText( void ) const;

                static void validate( const Data& data );
            };

            class TextDocumentIdentifier : public Data
            {
              public:
                TextDocumentIdentifier( const Data& data );

                TextDocumentIdentifier( const DocumentUri& uri );

                DocumentUri uri( void ) const;

                static void validate( const Data& data );
            };

            class VersionedTextDocumentIdentifier : public TextDocumentIdentifier
            {
              public:
                VersionedTextDocumentIdentifier( const Data& data );

                VersionedTextDocumentIdentifier(
                    const DocumentUri& uri, const std::size_t version );

                std::size_t version( void ) const;

                static void validate( const Data& data );
            };

            class TextDocumentEdit : public Data
            {
              public:
                TextDocumentEdit( const Data& data );

                TextDocumentEdit(
                    const VersionedTextDocumentIdentifier& textDocument,
                    const std::vector< TextEdit >& edits );

                VersionedTextDocumentIdentifier textDocument( void ) const;

                Data edits( void ) const;

                static void validate( const Data& data );
            };

            class WorkspaceEdit : public Data
            {
              public:
                WorkspaceEdit( const Data& data );

                WorkspaceEdit( void );

                // changes interface omitted!

                u1 hasDocumentChanges( void ) const;

                Data documentChanges( void ) const;

                void addDocumentChange( const TextDocumentEdit& documentChange );

                static void validate( const Data& data );
            };

            class CreateFileOptions : public Data
            {
              public:
                CreateFileOptions( const Data& data );

                CreateFileOptions( const u1 overwrite, const u1 ignoreIfExists );

                u1 hasOverwrite( void ) const;

                u1 overwrite( void ) const;

                void setOverwrite( const u1 overwrite );

                u1 hasIgnoreIfExists( void ) const;

                u1 ignoreIfExists( void ) const;

                void setIgnoreIfExists( const u1 ignoreIfExists );

                static void validate( const Data& data );
            };

            class CreateFile : public Data
            {
              public:
                CreateFile( const Data& data );

                CreateFile( const DocumentUri& uri );

                DocumentUri uri( void ) const;

                std::string kind( void ) const;

                u1 hasOptions( void ) const;

                void setOptions( const CreateFileOptions& options );

                CreateFileOptions options( void ) const;

                static void validate( const Data& data );
            };

            using RenameFileOptions = CreateFileOptions;

            class RenameFile : public Data
            {
              public:
                RenameFile( const Data& data );

                RenameFile( const DocumentUri& oldUri, const DocumentUri& newUri );

                DocumentUri newUri( void ) const;

                DocumentUri oldUri( void ) const;

                std::string kind( void ) const;

                u1 hasOptions( void ) const;

                void setOptions( const CreateFileOptions& options );

                CreateFileOptions options( void ) const;

                static void validate( const Data& data );
            };

            class DeleteFileOptions : public Data
            {
              public:
                DeleteFileOptions( const Data& data );

                u1 hasRecursive( void ) const;

                u1 recursive( void ) const;

                void setRecursive( const u1 recursive );

                u1 hasIgnoreIfExists( void ) const;

                u1 ignoreIfExists( void ) const;

                void setIgnoreIfExists( const u1 ignoreIfExists );

                static void validate( const Data& data );
            };

            class DeleteFile : public Data
            {
              public:
                DeleteFile( const Data& data );

                DeleteFile( const DocumentUri& uri );

                DocumentUri uri( void ) const;

                std::string kind( void ) const;

                u1 hasOptions( void ) const;

                void setOptions( const DeleteFileOptions& options );

                DeleteFileOptions options( void ) const;

                static void validate( const Data& data );
            };

            class TextDocumentItem : public Data
            {
              public:
                TextDocumentItem( const Data& data );

                TextDocumentItem(
                    const DocumentUri& uri,
                    const std::string& languageId,
                    const std::size_t version,
                    const std::string& text );

                DocumentUri uri( void ) const;

                std::string languageId( void ) const;

                std::size_t version( void ) const;

                std::string text( void ) const;

                static void validate( const Data& data );
            };

            class TextDocumentPositionParams : public Data
            {
              public:
                TextDocumentPositionParams( const Data& data );

                TextDocumentPositionParams(
                    const TextDocumentIdentifier& textDocument, const Position& position );

                TextDocumentIdentifier textDocument( void ) const;

                Position position( void ) const;

                static void validate( const Data& data );
            };

            class DocumentFilter : public Data
            {
              public:
                DocumentFilter( const Data& data );

                DocumentFilter( void );

                u1 hasLanguage( void ) const;

                std::string language( void ) const;

                void setLanguage( const std::string& language );

                u1 hasScheme( void ) const;

                std::string scheme( void ) const;

                void setScheme( const std::string& scheme );

                u1 hasPattern( void ) const;

                std::string pattern( void ) const;

                void setPattern( const std::string& pattern );

                static void validate( const Data& data );
            };

            class DocumentSelector : public Data
            {
              public:
                DocumentSelector( const Data& data );

                DocumentSelector( const std::vector< DocumentFilter >& documentFilters );

                static void validate( const Data& data );
            };

            //
            //
            // Actual Protocol
            //

            class DynamicRegistration : public Data
            {
              public:
                DynamicRegistration( const Data& data );

                DynamicRegistration( void );

                u1 hasDynamicRegistration( void ) const;

                u1 dynamicRegistration( void ) const;

                void setDynamicRegistration( const u1 dynamicRegistration );

                static void validate( const Data& data );
            };

            class WorkspaceClientCapabilities : public Data
            {
              public:
                WorkspaceClientCapabilities( const Data& data );

                WorkspaceClientCapabilities( void );

                u1 hasApplyEdit( void ) const;

                u1 applyEdit( void ) const;

                void setApplyEdit( const u1 applyEdit );

                u1 hasWorkspaceEdit( void ) const;

                WorkspaceEdit workspaceEdit( void ) const;

                void setWorkspaceEdit( const WorkspaceEdit& workspaceEdit );

                u1 hasDidChangeConfiguration( void ) const;

                DynamicRegistration didChangeConfiguration( void ) const;

                void setDidChangeConfiguration( const DynamicRegistration& didChangeConfiguration );

                u1 hasDidChangeWatchedFiles( void ) const;

                DynamicRegistration didChangeWatchedFiles( void ) const;

                void didChangeWatchedFiles( const DynamicRegistration& didChangeWatchedFiles );

                u1 hasSymbol( void ) const;

                DynamicRegistration symbol( void ) const;

                void setSymbol( const DynamicRegistration& symbol );

                u1 hasExecuteCommand( void ) const;

                DynamicRegistration executeCommand( void ) const;

                void executeCommand( const DynamicRegistration& executeCommand );

                u1 hasWorkspaceFolders( void ) const;

                void setWorkspaceFolders( const u1 workspaceFolders );

                u1 workspaceFolders( void ) const;

                u1 hasConfiguration( void ) const;

                void setConfiguration( const u1 configuration );

                u1 configuration( void ) const;

                static void validate( const Data& data );
            };

            class Synchronization : public Data
            {
              public:
                Synchronization( const Data& data );

                Synchronization( void );

                u1 hasDynamicRegistration( void ) const;

                u1 dynamicRegistration( void ) const;

                void setDynamicRegistration( const u1 dynamicRegistration );

                u1 hasWillSave( void ) const;

                u1 willSave( void ) const;

                void setWillSave( const u1 willSave );

                u1 hasWillSaveWaitUntil( void ) const;

                u1 willSaveWaitUntil( void ) const;

                void setWillSaveWaitUntil( const u1 willSaveWaitUntil );

                u1 hasDidSave( void ) const;

                u1 didSave( void ) const;

                void setDidSave( const u1 didSave );

                static void validate( const Data& data );
            };

            class TextDocumentClientCapabilities : public Data
            {
                class CompletionItem;
                class Completion;

              public:
                TextDocumentClientCapabilities( const Data& data );

                TextDocumentClientCapabilities( void );

                u1 hasSynchronization( void ) const;

                Synchronization synchronization( void ) const;

                void setSynchronization( const Synchronization& synchronization );

                u1 hasCompletion( void ) const;

                Completion completion( void ) const;

                void setCompletion( const Completion& completion );

                u1 hasHover( void ) const;

                DynamicRegistration hover( void ) const;

                void setHover( const DynamicRegistration& hover );

                u1 hasSignatureHelp( void ) const;

                DynamicRegistration signatureHelp( void ) const;

                void setSignatureHelp( const DynamicRegistration& signatureHelp );

                u1 hasReferences( void ) const;

                DynamicRegistration references( void ) const;

                void setReferences( const DynamicRegistration& references );

                u1 hasDocumentHighlight( void ) const;

                DynamicRegistration documentHighlight( void ) const;

                void setDocumentHighlight( const DynamicRegistration& documentHighlight );

                u1 hasDocumentSymbol( void ) const;

                DynamicRegistration documentSymbol( void ) const;

                void setDocumentSymbol( const DynamicRegistration& documentSymbol );

                u1 hasFormatting( void ) const;

                DynamicRegistration formatting( void ) const;

                void setFormatting( const DynamicRegistration& formatting );

                u1 hasRangeFormatting( void ) const;

                DynamicRegistration rangeFormatting( void ) const;

                void setRangeFormatting( const DynamicRegistration& rangeFormatting );

                u1 hasOnTypeFormatting( void ) const;

                DynamicRegistration onTypeFormatting( void ) const;

                void setOnTypeFormatting( const DynamicRegistration& onTypeFormatting );

                u1 hasDefinition( void ) const;

                DynamicRegistration definition( void ) const;

                void setDefinition( const DynamicRegistration& definition );

                u1 hasCodeAction( void ) const;

                DynamicRegistration codeAction( void ) const;

                void setCodeAction( const DynamicRegistration& codeAction );

                u1 hasCodeLens( void ) const;

                DynamicRegistration codeLens( void ) const;

                void setCodeLens( const DynamicRegistration& codeLens );

                u1 hasDocumentLink( void ) const;

                DynamicRegistration documentLink( void ) const;

                void setDocumentLink( const DynamicRegistration& documentLink );

                u1 hasRename( void ) const;

                DynamicRegistration rename( void ) const;

                void setRename( const DynamicRegistration& rename );

                static void validate( const Data& data );

              private:
                class Completion : public Data
                {
                  public:
                    Completion( const Data& data );

                    Completion( void );

                    u1 hasDynamicRegistration( void ) const;

                    u1 dynamicRegistration( void ) const;

                    void setDynamicRegistration( const u1 dynamicRegistration );

                    u1 hasCompletionItem( void ) const;

                    CompletionItem completionItem( void ) const;

                    void completionItem( const CompletionItem& completionItem );

                    static void validate( const Data& data );
                };

                class CompletionItem : public Data
                {
                  public:
                    CompletionItem( const Data& data );

                    CompletionItem( void );

                    u1 hasSnippetSupport( void ) const;

                    u1 snippetSupport( void ) const;

                    void setSnippetSupport( const u1 snippetSupport );

                    static void validate( const Data& data );
                };
            };

            class ClientCapabilities : public Data
            {
              public:
                ClientCapabilities( const Data& data );

                ClientCapabilities( void );

                u1 hasWorkspace( void ) const;

                WorkspaceClientCapabilities workspace( void ) const;

                void setWorkspace( const WorkspaceClientCapabilities& workspace );

                u1 hasTextDocument( void ) const;

                TextDocumentClientCapabilities textDocument( void ) const;

                void setTextDocument( const TextDocumentClientCapabilities& textDocument );

                u1 hasExperimental( void ) const;

                Data experimental( void ) const;

                void setExperimental( const Data& experimental );

                static void validate( const Data& data );
            };

            class SaveOptions : public Data
            {
              public:
                SaveOptions( const Data& data );

                SaveOptions( void );

                u1 hasIncludeText( void ) const;

                u1 includeText( void ) const;

                void setIncludeText( const u1 includeText );

                static void validate( const Data& data );
            };

            enum class TextDocumentSyncKind
            {
                None = 0,
                Full = 1,
                Incremental = 2,
            };

            class TextDocumentSyncOptions : public Data
            {
              public:
                TextDocumentSyncOptions( const Data& data );

                TextDocumentSyncOptions( void );

                u1 hasOpenClose( void ) const;

                u1 openClose( void ) const;

                void setOpenClose( const u1 openClose );

                u1 hasChange( void ) const;

                TextDocumentSyncKind change( void ) const;

                void setChange( const TextDocumentSyncKind& change );

                u1 hasWillSave( void ) const;

                u1 willSave( void ) const;

                void setWillSave( const u1 willSave );

                u1 hasWillSaveWaitUntil( void ) const;

                u1 willSaveWaitUntil( void ) const;

                void setWillSaveWaitUntil( const u1 willSaveWaitUntil );

                u1 hasSave( void ) const;

                SaveOptions save( void ) const;

                void setSave( const SaveOptions& save );

                static void validate( const Data& data );
            };

            class CompletionOptions : public Data
            {
              public:
                CompletionOptions( const Data& data );

                CompletionOptions( void );

                u1 hasResolveProvider( void ) const;

                u1 resolveProvider( void ) const;

                void setResolveProvider( const u1 resolveProvider );

                u1 hasTriggerCharacters( void ) const;

                Data triggerCharacters( void ) const;

                void addTriggerCharacters( const std::string& triggerCharacter );

                static void validate( const Data& data );
            };

            class SignatureHelpOptions : public Data
            {
              public:
                SignatureHelpOptions( const Data& data );

                SignatureHelpOptions( void );

                u1 hasTriggerCharacters( void ) const;

                Data triggerCharacters( void ) const;

                void addTriggerCharacters( const std::string& triggerCharacter );

                static void validate( const Data& data );
            };

            class CodeLensOptions : public Data
            {
              public:
                CodeLensOptions( const Data& data );

                CodeLensOptions( void );

                u1 hasResolveProvider( void ) const;

                u1 resolveProvider( void ) const;

                void setResolveProvider( const u1 resolveProvider );

                static void validate( const Data& data );
            };

            class DocumentOnTypeFormattingOptions : public Data
            {
              public:
                DocumentOnTypeFormattingOptions( const Data& data );

                DocumentOnTypeFormattingOptions( const std::string& firstTriggerCharacter );

                std::string firstTriggerCharacter( void ) const;

                u1 hasMoreTriggerCharacter( void ) const;

                Data moreTriggerCharacter( void ) const;

                void addMoreTriggerCharacter( const Data& moreTriggerCharacter );

                static void validate( const Data& data );
            };

            class RenameOptions : public Data
            {
              public:
                RenameOptions( const Data& data );

                u1 hasPrepareProvider( void ) const;

                u1 prepareProvider( void ) const;

                void setPrepareProvider( const u1 prepareProvider );

                static void validate( const Data& data );
            };

            using DocumentLinkOptions = CodeLensOptions;

            class ExecuteCommandOptions : public Data
            {
              public:
                ExecuteCommandOptions( const Data& data );

                ExecuteCommandOptions( void );

                u1 hasCommands( void ) const;

                Data commands( void ) const;

                void addCommand( const std::string& command );

                static void validate( const Data& data );
            };

            class StaticRegistrationOptions : public Data
            {
              public:
                StaticRegistrationOptions( const Data& data );

                u1 hasId( void ) const;

                std::string id( void ) const;

                void setId( std::string id );

                static void validate( const Data& data );
            };

            class TextDocumentRegistrationOptions : public Data
            {
              public:
                TextDocumentRegistrationOptions( const Data& data );

                TextDocumentRegistrationOptions( const DocumentSelector& documentSelector );

                DocumentSelector documentSelector( void ) const;

                static void validate( const Data& data );
            };

            class TypeDefinitionProvider : public Data
            {
              public:
                TypeDefinitionProvider( const Data& data );

                DocumentSelector documentSelector( void ) const;

                u1 hasId( void ) const;

                std::string id( void ) const;

                void setId( std::string id );

                static void validate( const Data& data );
            };

            using ImplementationProvider = TypeDefinitionProvider;

            class ColorProviderOptions : public Data
            {
              public:
                ColorProviderOptions( const Data& data );

                static void validate( const Data& data );
            };

            using FoldingRangeProviderOptions = ColorProviderOptions;

            class ColorProvider : public Data
            {
              public:
                ColorProvider( const Data& data );

                DocumentSelector documentSelector( void ) const;

                u1 hasId( void ) const;

                std::string id( void ) const;

                void setId( std::string id );

                static void validate( const Data& data );
            };

            using FoldingRangeProvider = ColorProvider;

            class Workspace : public Data
            {
              public:
                Workspace( const Data& data );

                static void validate( const Data& data );

                class WorkspaceFolders : public Data
                {
                  public:
                    WorkspaceFolders( const Data& data );

                    u1 supported( void ) const;

                    u1 hasSupported( void ) const;

                    void setSupported( const u1 supported );

                    void setChangeNotifications( const std::string& changeNotifications );

                    void setChangeNotifications( const u1 changeNotifications );

                    u1 hasChangeNotifications( void ) const;

                    std::string changeNotifications( void ) const;

                    static void validate( const Data& data );
                };
                WorkspaceFolders workspaceFolders( void ) const;

                u1 hasWorkspaceFolders( void ) const;

                void setWorkspaceFolders( const WorkspaceFolders& workspaceFolders );
            };

            class ServerCapabilities : public Data
            {
              public:
                ServerCapabilities( const Data& data );

                ServerCapabilities( void );

                u1 hasTextDocumentSync( void ) const;

                TextDocumentSyncOptions textDocumentSync( void ) const;

                void setTextDocumentSync( const TextDocumentSyncOptions& textDocumentSync );

                void setTextDocumentSync( const TextDocumentSyncKind& textDocumentSync );

                u1 hasHoverProvider( void ) const;

                u1 hoverProvider( void ) const;

                void setHoverProvider( const u1 hoverProvider );

                u1 hasCompletionProvider( void ) const;

                CompletionOptions completionProvider( void ) const;

                void setCompletionProvider( const CompletionOptions& completionProvider );

                u1 hasSignatureHelpProvider( void ) const;

                SignatureHelpOptions signatureHelpProvider( void ) const;

                void setSignatureHelpProvider( const SignatureHelpOptions& signatureHelpProvider );

                u1 hasDefinitionProvider( void ) const;

                u1 definitionProvider( void ) const;

                void setDefinitionProvider( const u1 definitionProvider );

                u1 hasTypeDefinitionProvider( void ) const;

                TypeDefinitionProvider typeDefinitionProvider( void ) const;

                void setTypeDefinitionProvider(
                    const TypeDefinitionProvider& typeDefinitionProvider );

                u1 hasImplementationProvider( void ) const;

                ImplementationProvider implementationProvider( void ) const;

                void setImplementationProvider(
                    const ImplementationProvider& implementationProvider );

                u1 hasReferencesProvider( void ) const;

                u1 referencesProvider( void ) const;

                void setReferencesProvider( const u1 referencesProvider );

                u1 hasDocumentHighlightProvider( void ) const;

                u1 documentHighlightProvider( void ) const;

                void setDocumentHighlightProvider( const u1 documentHighlightProvider );

                u1 hasDocumentSymbolProvider( void ) const;

                u1 documentSymbolProvider( void ) const;

                void setDocumentSymbolProvider( const u1 documentSymbolProvider );

                u1 hasWorkspaceSymbolProvider( void ) const;

                u1 workspaceSymbolProvider( void ) const;

                void setWorkspaceSymbolProvider( const u1 workspaceSymbolProvider );

                u1 hasCodeActionProvider( void ) const;

                u1 codeActionProvider( void ) const;

                void setCodeActionProvider( const u1 codeActionProvider );

                u1 hasCodeLensProvider( void ) const;

                CodeLensOptions codeLensProvider( void ) const;

                void setCodeLensProvider( const CodeLensOptions& codeLensProvider );

                u1 hasDocumentFormattingProvider( void ) const;

                u1 documentFormattingProvider( void ) const;

                void setDocumentFormattingProvider( const u1 documentFormattingProvider );

                u1 hasDocumentRangeFormattingProvider( void ) const;

                u1 documentRangeFormattingProvider( void ) const;

                void setDocumentRangeFormattingProvider( const u1 documentRangeFormattingProvider );

                u1 hasDocumentOnTypeFormattingProvider( void ) const;

                DocumentOnTypeFormattingOptions documentOnTypeFormattingProvider( void ) const;

                void setDocumentOnTypeFormattingProvider(
                    const DocumentOnTypeFormattingOptions& documentOnTypeFormattingProvider );

                u1 hasRenameProvider( void ) const;

                u1 renameProvider( void ) const;

                void setRenameProvider( const u1 renameProvider );

                u1 hasDocumentLinkProvider( void ) const;

                DocumentLinkOptions documentLinkProvider( void ) const;

                void setDocumentLinkProvider( const DocumentLinkOptions& documentLinkProvider );

                u1 hasColorProvider( void ) const;

                ColorProvider colorProvider( void ) const;

                void setColorProvider( const ColorProvider& colorProvider );

                u1 hasFoldingRangeProvider( void ) const;

                FoldingRangeProvider foldingRangeProvider( void ) const;

                void setFoldingRangeProvider( const FoldingRangeProvider& foldingRangeProvider );

                u1 hasExecuteCommandProvider( void ) const;

                ExecuteCommandOptions executeCommandProvider( void ) const;

                void setExecuteCommandProvider(
                    const ExecuteCommandOptions& executeCommandProvider );

                u1 hasExperimental( void ) const;

                Data experimental( void ) const;

                void setExperimental( const Data& experimental );

                u1 hasWorkspace( void ) const;

                void setWorkspace( const Workspace& workspace );

                Workspace workspace( void ) const;

                static void validate( const Data& data );
            };

            class WorkspaceFolder : public Data
            {
              public:
                WorkspaceFolder( const std::string& uri, const std::string& name );

                WorkspaceFolder( const Data& data );

                std::string uri( void ) const;

                std::string name( void ) const;

                static void validate( const Data& data );
            };

            using WorkspaceFolders = std::vector< WorkspaceFolder >;

            class InitializeParams : public Data
            {
              public:
                InitializeParams( const Data& data );

                InitializeParams(
                    const std::size_t processId,
                    const DocumentUri& rootUri,
                    const ClientCapabilities& capabilities );

                std::size_t processId( void ) const;

                // rootPath interface omitted!

                DocumentUri rootUri( void ) const;

                u1 hasInitializationOptions( void ) const;

                Data initializationOptions( void ) const;

                void setInitializationOptions( const Data& initializationOptions );

                ClientCapabilities capabilities( void ) const;

                u1 hasTrace( void ) const;

                std::string trace( void ) const;

                void setTrace( const std::string& trace );

                WorkspaceFolders workspaceFolders( void ) const;

                u1 hasWorkspaceFolders( void ) const;

                void addWorkspaceFolder( WorkspaceFolder folder );

                static void validate( const Data& data );
            };

            class InitializeResult : public Data
            {
              public:
                InitializeResult( const Data& data );

                InitializeResult( const ServerCapabilities& capabilities );

                ServerCapabilities capabilities( void ) const;

                static void validate( const Data& data );
            };

            class InitializeError : public Data
            {
              public:
                InitializeError( const Data& data );

                InitializeError( const u1 retry );

                u1 retry( void ) const;

                static void validate( const Data& data );
            };

            enum class MessageType
            {
                Error = 1,

                Warning = 2,

                Info = 3,

                Log = 4
            };

            class CancelParams : public Data
            {
              public:
                CancelParams( const Data& data );

                CancelParams( const std::size_t& id );

                CancelParams( const std::string& id );

                std::string id( void ) const;

                static void validate( const Data& data );
            };

            class ShowMessageParams : public Data
            {
              public:
                ShowMessageParams( const Data& data );

                ShowMessageParams( const MessageType type, const std::string& message );

                MessageType messageType( void ) const;

                std::string message( void ) const;

                static void validate( const Data& data );
            };

            class MessageActionItem : public Data
            {
              public:
                MessageActionItem( const Data& data );

                MessageActionItem( const std::string& title );

                std::string title( void ) const;

                static void validate( const Data& data );
            };

            class ShowMessageRequestResult : public Data
            {
              public:
                ShowMessageRequestResult( void );

                ShowMessageRequestResult( const Data& data );

                ShowMessageRequestResult( const MessageActionItem& item );

                ShowMessageRequestResult( const std::string& title );

                static void validate( const Data& data );
            };

            using MessageActionItems = std::vector< MessageActionItem >;

            class ShowMessageRequestParams : public Data
            {
              public:
                ShowMessageRequestParams( const Data& data );

                ShowMessageRequestParams( const MessageType type, const std::string& message );

                MessageType messageType( void ) const;

                u1 hasActions( void );

                MessageActionItems actions( void ) const;

                void addAction( const MessageActionItem& action );

                std::string message( void ) const;

                static void validate( const Data& data );
            };

            using LogMessageParams = ShowMessageParams;

            class TelemetryEventParams : public Data
            {
              public:
                TelemetryEventParams( const Data& data );

                static void validate( const Data& data );
            };

            class Registration : public Data
            {
              public:
                Registration( const Data& data );

                Registration( const std::string& id, const std::string& method );

                std::string id( void ) const;

                std::string method( void ) const;

                Data registerOptions( void ) const;

                u1 hasRegisterOptions( void ) const;

                void addRegisterOption( const Data& option );

                static void validate( const Data& data );
            };

            using Registrations = std::vector< Registration >;

            class RegistrationParams : public Data
            {
              public:
                RegistrationParams( const Data& data );

                RegistrationParams( const Registrations& registrations );

                Registrations registrations( void ) const;

                static void validate( const Data& data );
            };

            class TextDocumentChangeRegistrationOptions : public TextDocumentRegistrationOptions
            {
              public:
                TextDocumentChangeRegistrationOptions( const Data& data );

                TextDocumentChangeRegistrationOptions(
                    const DocumentSelector& documentSelector, TextDocumentSyncKind kind );

                TextDocumentSyncKind kind( void ) const;

                static void validate( const Data& data );
            };

            class TextDocumentSaveRegistrationOptions : public TextDocumentRegistrationOptions
            {
              public:
                TextDocumentSaveRegistrationOptions( const Data& data );

                TextDocumentSaveRegistrationOptions( const DocumentSelector& documentSelector );

                u1 hasIncludeText( void ) const;

                void setIncludeText( const u1 includeText );

                u1 includeText( void ) const;

                static void validate( const Data& data );
            };

            using TriggerCharacters = std::vector< std::string >;

            class SignatureHelpRegistrationOptions : public TextDocumentRegistrationOptions
            {
              public:
                SignatureHelpRegistrationOptions( const Data& data );

                SignatureHelpRegistrationOptions( const DocumentSelector& documentSelector );

                u1 hasTriggerCharacters( void ) const;

                void setTriggerCharacters( const TriggerCharacters& triggerCharacters );

                void addTriggerCharacter( const std::string& triggerCharacter );

                TriggerCharacters triggerCharacters( void ) const;

                static void validate( const Data& data );
            };

            class Unregistration : public Data
            {
              public:
                Unregistration( const Data& data );

                Unregistration( const std::string& id, const std::string& method );

                std::string id( void ) const;

                std::string method( void ) const;

                static void validate( const Data& data );
            };
            using Unregistrations = std::vector< Unregistration >;

            class UnregistrationParams : public Data
            {
              public:
                UnregistrationParams( const Unregistrations& unregistrations );

                UnregistrationParams( const Data& data );

                Unregistrations unregistrations( void ) const;

                static void validate( const Data& data );
            };

            class WorkspaceFoldersResult : public Data
            {
              public:
                WorkspaceFoldersResult();

                WorkspaceFoldersResult( const Data& data );

                WorkspaceFoldersResult( const WorkspaceFolders& workspaceFolders );

                WorkspaceFolders workspaceFolders( void ) const;

                static void validate( const Data& data );
            };

            class WorkspaceFoldersChangeEvent : public Data
            {
              public:
                WorkspaceFoldersChangeEvent(
                    const WorkspaceFolders& added, const WorkspaceFolders& removed );

                WorkspaceFoldersChangeEvent( const Data& data );

                WorkspaceFolders added( void ) const;

                WorkspaceFolders removed( void ) const;

                static void validate( const Data& data );
            };

            class DidChangeWorkspaceFoldersParams : public Data
            {
              public:
                DidChangeWorkspaceFoldersParams( const Data& data );

                DidChangeWorkspaceFoldersParams( const WorkspaceFoldersChangeEvent& event );

                WorkspaceFoldersChangeEvent event( void ) const;

                static void validate( const Data& data );
            };

            using DidChangeConfigurationSettings = Data;

            class DidChangeConfigurationParams : public Data
            {
              public:
                DidChangeConfigurationParams( const DidChangeConfigurationSettings& settings );

                DidChangeConfigurationSettings settings( void ) const;

                static void validate( const Data& data );
            };

            class ConfigurationItem : public Data
            {
              public:
                ConfigurationItem( const Data& data );

                ConfigurationItem( const std::string& scopeUri, const std::string& section );

                u1 hasScopeUri( void ) const;

                u1 hasSection( void ) const;

                std::string scopeUri( void ) const;

                std::string section( void ) const;

                void setSection( const std::string& section );

                void setScopeUri( const std::string& uri );

                static void validate( const Data& data );
            };

            class ConfigurationResult : public Data
            {
              public:
                ConfigurationResult( void );

                ConfigurationResult( const Data& data );

                static void validate( const Data& data );
            };

            using ConfigurationItems = std::vector< ConfigurationItem >;

            class ConfigurationParams : public Data
            {
              public:
                ConfigurationParams( const ConfigurationItems& items );

                ConfigurationParams( const Data& data );

                ConfigurationItems items( void ) const;

                static void validate( const Data& data );
            };

            enum class FileChangeType
            {
                Created = 1,
                Changed = 2,
                Deleted = 3
            };

            class FileEvent : public Data
            {
              public:
                FileEvent( const Data& data );

                FileEvent( const DocumentUri& uri, const FileChangeType type );

                DocumentUri documentUri( void ) const;

                FileChangeType type( void ) const;

                static void validate( const Data& data );
            };

            using FileEvents = std::vector< FileEvent >;

            class DidChangeWatchedFilesParams : public Data
            {
              public:
                DidChangeWatchedFilesParams( const FileEvents& changes );

                DidChangeWatchedFilesParams( const Data& data );

                FileEvents changes( void ) const;

                static void validate( const Data& data );
            };

            enum class WatchKind
            {
                Create = 1,
                Change = 2,
                Delete = 4
            };

            class FileSystemWatcher : public Data
            {
              public:
                FileSystemWatcher( const Data& data );

                FileSystemWatcher( const std::string& globPattern );

                FileSystemWatcher( const std::string& globPattern, const WatchKind kind );

                std::string globPattern( void );

                u1 hasKind( void ) const;

                WatchKind kind( void ) const;

                static void validate( const Data& data );

                void setKind( const WatchKind kind );
            };

            using FileSystemWatchers = std::vector< FileSystemWatcher >;

            class DidChangeWatchedFilesRegistrationOptions : public Data
            {
              public:
                DidChangeWatchedFilesRegistrationOptions( const FileSystemWatchers& watchers );

                DidChangeWatchedFilesRegistrationOptions( const Data& data );

                FileSystemWatchers watchers( void ) const;

                static void validate( const Data& data );
            };

            class WorkspaceSymbolParams : public Data
            {
              public:
                WorkspaceSymbolParams( const Data& data );

                WorkspaceSymbolParams( const std::string& query );

                std::string query( void ) const;

                static void validate( const Data& data );
            };

            enum class SymbolKind
            {
                File = 1,
                Module = 2,
                Namespace = 3,
                Package = 4,
                Class = 5,
                Method = 6,
                Property = 7,
                Field = 8,
                Constructor = 9,
                Enum = 10,
                Interface = 11,
                Function = 12,
                Variable = 13,
                Constant = 14,
                String = 15,
                Number = 16,
                Boolean = 17,
                Array = 18,
                Object = 19,
                Key = 20,
                Null = 21,
                EnumMember = 22,
                Struct = 23,
                Event = 24,
                Operator = 25,
                TypeParameter = 26
            };

            class SymbolInformation : public Data
            {
              public:
                SymbolInformation(
                    const std::string& name, const SymbolKind kind, const Location& location );

                SymbolInformation( const Data& data );

                u1 isDeprecated( void ) const;

                u1 hasDeprecated( void ) const;

                void setDeprecated( const u1 deprecated );

                std::string containerName( void ) const;

                u1 hasContainerName( void ) const;

                void setContainerName( const std::string& containerName );

                Location location( void ) const;

                std::string name( void ) const;

                SymbolKind kind( void ) const;

                static void validate( const Data& data );
            };

            using SymbolInformations = std::vector< SymbolInformation >;

            class WorkspaceSymbolResult : public Data
            {
              public:
                WorkspaceSymbolResult( const Data& data );

                WorkspaceSymbolResult( const SymbolInformations& symbolInformation );

                void addSymbolInformation( const SymbolInformation& information );

                SymbolInformations symbolInformation( void ) const;

                static void validate( const Data& data );
            };

            class ApplyWorkspaceEditParams : public Data
            {
              public:
                ApplyWorkspaceEditParams( const Data& data );

                ApplyWorkspaceEditParams( const WorkspaceEdit& edit );

                WorkspaceEdit edit( void ) const;

                u1 hasLabel( void ) const;

                std::string label( void ) const;

                void setLabel( const std::string& label );

                static void validate( const Data& data );
            };

            class ApplyWorkspaceEditResult : public Data
            {
              public:
                ApplyWorkspaceEditResult( const Data& data );

                ApplyWorkspaceEditResult( const u1 applied );

                u1 applied( void ) const;

                static void validate( const Data& data );
            };

            class DidOpenTextDocumentParams : public Data
            {
              public:
                DidOpenTextDocumentParams( const Data& data );

                DidOpenTextDocumentParams( const TextDocumentItem& textDocument );

                TextDocumentItem textDocument( void ) const;

                static void validate( const Data& data );
            };

            class TextDocumentContentChangeEvent : public Data
            {
              public:
                TextDocumentContentChangeEvent( const Data& data );

                TextDocumentContentChangeEvent( const std::string& text );

                u1 hasRange( void ) const;

                Range range( void ) const;

                void setRange( const Range& range );

                u1 hasRangeLength( void ) const;

                std::size_t rangeLength( void ) const;

                void setRangeLength( const std::size_t rangeLength );

                std::string text( void ) const;

                static void validate( const Data& data );
            };

            using TextDocumentContentChangeEvents = std::vector< TextDocumentContentChangeEvent >;

            class DidChangeTextDocumentParams : public Data
            {
              public:
                DidChangeTextDocumentParams( const Data& data );

                DidChangeTextDocumentParams(
                    const VersionedTextDocumentIdentifier& textDocument,
                    const TextDocumentContentChangeEvents& contentChanges );

                VersionedTextDocumentIdentifier textDocument( void ) const;

                TextDocumentContentChangeEvents contentChanges( void ) const;

                static void validate( const Data& data );
            };

            enum class TextDocumentSaveReason
            {
                Manual = 1,  // by the user pressing save, by starting debugging, or by an API call.
                AfterDelay = 2,  // Automatic after a delay.
                FocusOut = 3     //  When the editor lost focus.
            };

            class WillSaveTextDocumentParams : public Data
            {
              public:
                WillSaveTextDocumentParams( const Data& data );

                WillSaveTextDocumentParams(
                    const TextDocumentIdentifier& textDocument,
                    const TextDocumentSaveReason reason );

                TextDocumentSaveReason reason( void ) const;

                TextDocumentIdentifier textDocument( void ) const;

                static void validate( const Data& data );
            };

            using TextEdits = std::vector< TextEdit >;

            class WillSaveWaitUntilResponse : public Data
            {
              public:
                WillSaveWaitUntilResponse( const Data& data );

                WillSaveWaitUntilResponse( const TextEdits& textEdit );

                TextEdits textEdit( void ) const;

                static void validate( const Data& data );
            };

            class DidSaveTextDocumentParams : public Data
            {
              public:
                DidSaveTextDocumentParams( const Data& data );

                DidSaveTextDocumentParams( const TextDocumentIdentifier& textDocument );

                u1 hasText( void ) const;

                void setText( const std::string& text );

                TextDocumentIdentifier textDocument( void ) const;

                std::string text( void ) const;

                static void validate( const Data& data );
            };

            class DidCloseTextDocumentParams : public Data
            {
              public:
                DidCloseTextDocumentParams( const TextDocumentIdentifier& textDocument );

                DidCloseTextDocumentParams( const Data& data );

                TextDocumentIdentifier textDocument( void ) const;

                static void validate( const Data& data );
            };

            class CompletionRegistrationOptions : public TextDocumentRegistrationOptions
            {
              public:
                CompletionRegistrationOptions( const Data& data );

                CompletionRegistrationOptions( const DocumentSelector& documentSelector );

                u1 hasTriggerCharacters( void ) const;

                TriggerCharacters triggerCharacters( void ) const;

                void addTriggerCharacter( const std::string& triggerCharacter );

                u1 hasResolveProvider( void ) const;

                u1 resolveProvider( void ) const;

                void setResolveProvider( const u1 resolveProvider );

                static void validate( const Data& data );
            };

            enum class CompletionTriggerKind
            {
                Invoked = 1,  // via API, Ctrl+Space, or typing identifier (24x7 code complete)
                TriggerCharacter = 2,  // via triggerCharacters, see CompletionRegistrationOptions
                TriggerForIncompleteCompletions = 3  // re-triggered due to current incomplete list
            };

            class CompletionContext : public Data
            {
              public:
                CompletionContext( const Data& data );

                CompletionContext( const CompletionTriggerKind triggerkind );

                std::string triggerCharacter( void ) const;

                void setTriggerCharacter( const std::string& triggerCharacter );

                u1 hasTriggerCharacter( void ) const;

                CompletionTriggerKind triggerKind( void ) const;

                static void validate( const Data& data );
            };

            class CompletionParams : public TextDocumentPositionParams
            {
              public:
                CompletionParams( const Data& data );

                CompletionParams(
                    const TextDocumentIdentifier& textDocument, const Position& position );

                CompletionContext context( void ) const;

                u1 hasContext( void ) const;

                void setContext( const CompletionContext& context );

                static void validate( const Data& data );
            };

            enum class MarkupKind
            {
                PLAINTEXT,
                MARKDOWN
            };

            class MarkupContent : public Data
            {
              public:
                MarkupContent( const Data& data );

                MarkupContent( const std::string& value );  // kind will be plaintext

                MarkupContent( const MarkupKind kind, const std::string& value );

                std::string kind( void ) const;

                std::string value( void ) const;

                static void validate( const Data& data );
            };

            enum class InsertTextFormat
            {
                PlainText = 1,
                Snippet = 2
            };

            enum class CompletionItemKind
            {
                Text = 1,
                Method = 2,
                Function = 3,
                Constructor = 4,
                Field = 5,
                Variable = 6,
                Class = 7,
                Interface = 8,
                Module = 9,
                Property = 10,
                Unit = 11,
                Value = 12,
                Enum = 13,
                Keyword = 14,
                Snippet = 15,
                Color = 16,
                File = 17,
                Reference = 18,
                Folder = 19,
                EnumMember = 20,
                Constant = 21,
                Struct = 22,
                Event = 23,
                Operator = 24,
                TypeParameter = 25
            };

            using CommitCharacters = std::vector< std::string >;

            class CompletionItem : public Data
            {
              public:
                CompletionItem( const Data& data );

                CompletionItem( const std::string& label );

                std::string label( void ) const;

                u1 hasKind( void ) const;

                void setKind( const CompletionItemKind kind );

                CompletionItemKind kind( void ) const;

                u1 hasDetail( void ) const;

                void setDetail( const std::string& detail );

                std::string detail( void ) const;

                u1 hasDocumentation( void ) const;

                void setDocumentation( const MarkupContent& doc );

                MarkupContent documentation( void ) const;

                u1 hasDeprecated( void ) const;

                void setDeprecated( const u1 deprecated );

                u1 isDeprecated( void ) const;

                u1 hasPreselected( void ) const;

                void setPreselected( const u1 preselected );

                u1 isPreselected( void ) const;

                u1 hasSortText( void ) const;

                void setSortText( const std::string& sortText );

                std::string sortText( void ) const;

                u1 hasFilterText( void ) const;

                void setFilterText( const std::string& filterText );

                std::string filterText( void ) const;

                u1 hasInsertText( void ) const;

                void setInsertText( const std::string& insertText );

                std::string insertText( void ) const;

                u1 hasInsertTextFormat( void ) const;

                void setInsertTextFormat( const InsertTextFormat insertTextFormat );

                InsertTextFormat insertTextFormat( void ) const;

                u1 hasTextEdit( void ) const;

                void setTextEdit( const TextEdit& textEdit );

                TextEdit textEdit( void ) const;

                u1 hasAdditionalTextEdits( void ) const;

                void addAdditionalTextEdit( const TextEdit& textEdit );

                TextEdits additionalTextEdits( void ) const;

                u1 hasCommitCharacters( void ) const;

                void addCommitCharacter( const std::string& commitCharacter );

                CommitCharacters commitCharacters( void ) const;

                u1 hasCommand( void ) const;

                void setCommand( const Command& command );

                Command command( void ) const;

                u1 hasData( void ) const;

                void setData( const Data& data );

                Data data( void ) const;

                static void validate( const Data& data );
            };

            using CompletionItems = std::vector< CompletionItem >;

            class CompletionList : public Data
            {
              public:
                CompletionList( const Data& data );

                CompletionList( const u1 isIncomplete, const CompletionItems& items );

                CompletionItems items( void ) const;

                u1 isIncomplete( void ) const;

                static void validate( const Data& data );
            };

            using CompletionResolveResult = CompletionItem;

            using SignatureHelpParams = TextDocumentPositionParams;

            class CompletionResult : public Data
            {
              public:
                CompletionResult( void );

                CompletionResult( const Data& data );

                CompletionResult( const CompletionList& list );

                CompletionResult( const CompletionItems& items );

                static void validate( const Data& data );
            };

            class ParameterInformation : public Data
            {
              public:
                ParameterInformation( const Data& data );

                ParameterInformation( const std::string& label );

                std::string label( void ) const;

                MarkupContent documentation( void ) const;

                u1 hasDocumentation( void ) const;

                void setDocumentation( const MarkupContent& doc );

                static void validate( const Data& data );
            };

            using ParameterInformations = std::vector< ParameterInformation >;

            class SignatureInformation : public Data
            {
              public:
                SignatureInformation( const Data& data );

                SignatureInformation( const std::string& label );

                std::string label( void ) const;

                MarkupContent documentation( void ) const;

                u1 hasDocumentation( void ) const;

                void setDocumentation( const MarkupContent& doc );

                u1 hasParameters( void ) const;

                ParameterInformations parameters( void ) const;

                void setParameters( const ParameterInformations& parameters );

                static void validate( const Data& data );
            };

            using SignatureInformations = std::vector< SignatureInformation >;

            class SignatureHelp : public Data
            {
              public:
                SignatureHelp( const Data& data );

                SignatureHelp( const SignatureInformations& signatures );

                SignatureInformations signatures( void ) const;

                u1 hasActiveSignature( void ) const;

                void setActiveSignature( const std::size_t activeSignature );

                std::size_t activeSignature( void ) const;

                u1 hasActiveParameter( void ) const;

                void setActiveParameter( const std::size_t activeParameter );

                std::size_t activeParameter( void ) const;

                static void validate( const Data& data );
            };

            class SignatureHelpResult : public Data
            {
              public:
                SignatureHelpResult( void );

                SignatureHelpResult( const Data& data );

                SignatureHelpResult( const SignatureHelp& signature );

                static void validate( const Data& data );
            };

            using TypeDefinitionParams = TextDocumentPositionParams;

            using Locations = std::vector< Location >;

            class LocationLink : public Data
            {
              public:
                LocationLink( const Data& data );

                LocationLink( const DocumentUri& targetUri, const Range& targetRange );

                DocumentUri targetUri( void ) const;

                Range targetRange( void ) const;

                u1 hasOriginSelectionRange( void ) const;

                void setOriginSelectionRange( const Range& range );

                Range originSelectionRange( void ) const;

                u1 hasTargetSelectionRange( void ) const;

                void setTargetSelectionRange( const Range& range );

                Range targetSelectionRange( void ) const;

                static void validate( const Data& data );
            };

            using LocationLinks = std::vector< LocationLink >;

            class TypeDefinitionResult : public Data
            {
              public:
                TypeDefinitionResult( const Data& data );

                TypeDefinitionResult( const Locations& locations );

                TypeDefinitionResult( const LocationLinks& locationLinks );

                TypeDefinitionResult( const Location& location );

                static void validate( const Data& data );
            };

            using TextDocumentImplementationResult = TypeDefinitionResult;

            using TextDocumentImplementationParams = TextDocumentPositionParams;

            class ReferenceContext : public Data
            {
              public:
                ReferenceContext( const Data& data );

                ReferenceContext( const u1 includeDeclaration );

                u1 includeDeclaration( void ) const;

                static void validate( const Data& data );
            };

            class ReferenceParams : public TextDocumentPositionParams
            {
              public:
                ReferenceParams( const Data& data );

                ReferenceParams(
                    const TextDocumentIdentifier& textDocument,
                    const Position& position,
                    const ReferenceContext& context );

                ReferenceContext context( void ) const;

                static void validate( const Data& data );
            };

            class ReferenceResult : public Data
            {
              public:
                ReferenceResult( const Data& data );

                ReferenceResult( const Locations& locations );

                static void validate( const Data& data );
            };

            enum class CodeActionKind
            {
                QuickFix,
                Refactor,
                RefactorExtract,
                RefactorInline,
                RefactorRewrite,
                Source,
                SourceOrganizeImports
            };

            class CodeActionOptions : public Data
            {
              public:
                CodeActionOptions( const Data& data );

                u1 hasCodeActionKinds( void ) const;

                void addCodeActionKind( const CodeActionKind kind );

                std::vector< std::string > codeActionKinds( void ) const;

                static void validate( const Data& data );
            };

            using Diagnostics = std::vector< Diagnostic >;

            class CodeActionContext : public Data
            {
              public:
                CodeActionContext( const Data& data );

                CodeActionContext( const Diagnostics& diagnostics );

                Diagnostics diagnostics( void ) const;

                u1 hasKind( void ) const;

                void setKind( const CodeActionKind kind );

                std::string kind( void ) const;

                static void validate( const Data& data );
            };

            class CodeActionParams : public Data
            {
              public:
                CodeActionParams( const Data& data );

                CodeActionParams(
                    const TextDocumentIdentifier& textDocument,
                    const Range& range,
                    const CodeActionContext& context );

                TextDocumentIdentifier textDocument( void ) const;

                Range range( void ) const;

                CodeActionContext context( void ) const;

                static void validate( const Data& data );
            };

            class CodeAction : public Data
            {
              public:
                CodeAction( const Data& data );

                CodeAction( const std::string& title );

                std::string title( void ) const;

                u1 hasKind( void ) const;

                std::string kind( void ) const;

                void setKind( const CodeActionKind kind );

                u1 hasDiagnostics( void ) const;

                Diagnostics diagnostics( void ) const;

                void addDiagnostic( const Diagnostic& diagnostic );

                u1 hasEdit( void ) const;

                WorkspaceEdit edit( void ) const;

                void setEdit( const WorkspaceEdit& edit );

                void setCommand( const Command& command );

                u1 hasCommand( void ) const;

                Command command( void ) const;

                static void validate( const Data& data );
            };

            class CodeActionResult : public Data
            {
              public:
                CodeActionResult( const Data& data );

                CodeActionResult( const Commands& commands );

                CodeActionResult( void );

                void addCommand( const Command& command );

                static void validate( const Data& data );
            };

            class CodeActionRegistrationOptions
            : public TextDocumentRegistrationOptions
            , public CodeActionOptions
            {
            };

            class PublishDiagnosticsParams : public Data
            {
              public:
                PublishDiagnosticsParams( const Data& data );

                PublishDiagnosticsParams( const DocumentUri& uri, const Diagnostics& diagnostics );

                DocumentUri uri( void ) const;

                Diagnostics diagnostics( void ) const;

                static void validate( const Data& data );
            };

            using HoverParams = TextDocumentPositionParams;

            class MarkedString : public Data
            {
              public:
                MarkedString( const Data& data );

                MarkedString( const std::string& language, const std::string& value );

                std::string language( void ) const;

                std::string value( void ) const;

                static void validate( const Data& data );
            };

            using MarkedStrings = std::vector< MarkedString >;

            class HoverResult : public Data
            {
              public:
                HoverResult( const Data& data );

                HoverResult( const MarkedStrings& contents = {} );

                MarkedStrings contents( void ) const;

                void addContent( const MarkedString& content );

                u1 hasRange( void ) const;

                Range range( void ) const;

                void setRange( const Range& range );

                static void validate( const Data& data );
            };

            using DefinitionParams = TextDocumentPositionParams;

            class DefinitionResult : public Data
            {
              public:
                DefinitionResult( const Data& data );

                DefinitionResult( const Location& location );

                DefinitionResult( const Locations& locations );

                Locations locations( void ) const;

                static void validate( const Data& data );
            };

            using DocumentHighlightParams = TextDocumentPositionParams;

            enum class DocumentHighlightKind
            {
                Text = 1,
                Read = 2,
                Write = 3
            };

            class DocumentHighlight : public Data
            {
              public:
                DocumentHighlight( const Data& data );

                DocumentHighlight( const Range& range );

                Range range( void ) const;

                u1 hasKind( void ) const;

                DocumentHighlightKind kind( void ) const;

                void setKind( const DocumentHighlightKind kind );

                static void validate( const Data& data );
            };

            using DocumentHighlights = std::vector< DocumentHighlight >;

            class DocumentHighlightResult : public Data
            {
              public:
                DocumentHighlightResult( const Data& data );

                DocumentHighlightResult( const DocumentHighlights& highlights );

                DocumentHighlightResult( void );

                static void validate( const Data& data );
            };

            class DocumentSymbolParams : public Data
            {
              public:
                DocumentSymbolParams( const Data& data );

                DocumentSymbolParams( const TextDocumentIdentifier& textDocument );

                TextDocumentIdentifier textDocument( void ) const;

                static void validate( const Data& data );
            };

            class DocumentSymbol;

            using DocumentSymbols = std::vector< DocumentSymbol >;

            class DocumentSymbol : public Data
            {
              public:
                DocumentSymbol( const Data& data );

                DocumentSymbol(
                    const std::string& name,
                    const SymbolKind kind,
                    const Range& range,
                    const Range& selectionRange );

                std::string name( void ) const;

                SymbolKind kind( void ) const;

                Range range( void ) const;

                Range selectionRange( void ) const;

                u1 hasDetail( void ) const;

                void setDetail( const std::string& detail );

                std::string detail( void ) const;

                u1 hasDeprecated( void ) const;

                u1 deprecated( void ) const;

                void setDeprecated( const u1 deprecated );

                u1 hasChildren( void ) const;

                DocumentSymbols children( void ) const;

                void addChild( const DocumentSymbol& symbol );

                static void validate( const Data& data );
            };

            class DocumentSymbolResult : public Data
            {
              public:
                DocumentSymbolResult( void );

                DocumentSymbolResult( const Data& data );

                DocumentSymbolResult( const DocumentSymbols& symbols );

                DocumentSymbolResult( const SymbolInformations& information );

                static void validate( const Data& data );
            };

            class CodeLensParams : public Data
            {
              public:
                CodeLensParams( const Data& data );

                CodeLensParams( const TextDocumentIdentifier& textDocument );

                TextDocumentIdentifier textDocument( void ) const;

                static void validate( const Data& data );
            };

            class CodeLens : public Data
            {
              public:
                CodeLens( const Data& data );

                CodeLens( const Range& range );

                Range range( void ) const;

                u1 hasCommand( void ) const;

                Command command( void ) const;

                void setCommand( const Command& command );

                u1 hasData( void ) const;

                Data data( void ) const;

                void setData( const Data& data );

                static void validate( const Data& data );
            };

            class CodeLensResult : public Data
            {
              public:
                CodeLensResult( const Data& data );

                CodeLensResult( const std::vector< CodeLens >& codeLens = {} );

                void addCodeLens( const CodeLens& codeLens );

                static void validate( const Data& data );
            };

            class DocumentLinkParams : public Data
            {
              public:
                DocumentLinkParams( const Data& data );

                DocumentLinkParams( const TextDocumentIdentifier& textDocument );

                TextDocumentIdentifier textDocument( void ) const;

                static void validate( const Data& data );
            };

            class DocumentLink : public Data
            {
              public:
                DocumentLink( const Data& data );

                DocumentLink( const Range& range );

                Range range( void ) const;

                u1 hasTarget( void ) const;

                void setTarget( const DocumentUri& target );

                DocumentUri target( void ) const;

                u1 hasData( void ) const;

                void setData( const Data& data );

                Data data( void ) const;

                static void validate( const Data& data );
            };

            using DocumentLinks = std::vector< DocumentLink >;

            class DocumentLinkResult : public Data
            {
              public:
                DocumentLinkResult( void );

                DocumentLinkResult( const Data& data );

                DocumentLinkResult( const DocumentLinks links );

                static void validate( const Data& data );
            };

            using CodeLensResolveParams = CodeLens;
            using CodeLensResolveResult = CodeLens;
            using DocumentLinkResolveResult = DocumentLink;
            using DocumentLinkResolveParams = DocumentLink;

            class DocumentColorParams : public Data
            {
              public:
                DocumentColorParams( const Data& data );

                DocumentColorParams( const TextDocumentIdentifier& textDocument );

                TextDocumentIdentifier textDocument( void ) const;

                static void validate( const Data& data );
            };

            class Color : public Data
            {
              public:
                Color( const Data& data );

                Color( const float red, const float green, const float blue, const float alpha );

                float red( void ) const;

                float green( void ) const;

                float blue( void ) const;

                float alpha( void ) const;

                static void validate( const Data& data );
            };

            class ColorInformation : public Data
            {
              public:
                ColorInformation( const Data& data );

                ColorInformation( const Range& range, const Color& color );

                Range range( void ) const;

                Color color( void ) const;

                static void validate( const Data& data );
            };

            using ColorInformations = std::vector< ColorInformation >;

            class DocumentColorResult : public Data
            {
              public:
                DocumentColorResult( const Data& data );

                DocumentColorResult( const ColorInformations& colorInformations );

                static void validate( const Data& data );
            };

            class ColorPresentationParams : public DocumentColorParams
            {
              public:
                ColorPresentationParams( const Data& data );

                ColorPresentationParams(
                    const TextDocumentIdentifier& textDocument,
                    const Color& color,
                    const Range& range );

                Color color( void ) const;

                Range range( void ) const;

                static void validate( const Data& data );
            };

            class ColorPresentation : public Data
            {
              public:
                ColorPresentation( const Data& data );

                ColorPresentation( const std::string& label );

                std::string label( void ) const;

                u1 hasTextEdit( void ) const;

                void setTextEdit( const TextEdit& textEdit );

                TextEdit textEdit( void ) const;

                u1 hasAdditionalTextEdits( void ) const;

                void addAdditionalTextEdit( const TextEdit& textEdit );

                TextEdits additionalTextEdits( void ) const;

                static void validate( const Data& data );
            };

            using ColorPresentations = std::vector< ColorPresentation >;

            class ColorPresentationResult : public Data
            {
              public:
                ColorPresentationResult( const Data& data );

                ColorPresentationResult( ColorPresentations presentations );

                static void validate( const Data& data );
            };

            class FormattingOptions : public Data
            {
              private:
                static void validateAdditionalOptions( const Data& data );

              public:
                FormattingOptions( const Data& data );

                FormattingOptions( const std::size_t tabSize, const u1 insertSpaces );

                std::size_t tabSize( void ) const;

                void addBool( const std::string& key, const u1 boolean );

                void addNumber( const std::string& key, const float number );

                void addString( const std::string& key, const std::string& string );

                u1 insertSpaces( void ) const;

                static void validate( const Data& data );
            };

            class DocumentFormattingParams : public Data
            {
              public:
                DocumentFormattingParams( const Data& data );

                DocumentFormattingParams(
                    const TextDocumentIdentifier& textDocument, const FormattingOptions& options );

                TextDocumentIdentifier textDocument( void ) const;

                FormattingOptions options( void ) const;

                static void validate( const Data& data );
            };

            class DocumentFormattingResult : public Data
            {
              public:
                DocumentFormattingResult( void );

                DocumentFormattingResult( const Data& data );

                DocumentFormattingResult( const TextEdits& edits );

                static void validate( const Data& data );
            };

            class DocumentRangeFormattingParams : public DocumentFormattingParams
            {
              public:
                DocumentRangeFormattingParams( const Data& data );

                DocumentRangeFormattingParams(
                    const TextDocumentIdentifier& textDocument,
                    const Range& range,
                    const FormattingOptions& options );

                Range range( void ) const;

                static void validate( const Data& data );
            };

            class DocumentOnTypeFormattingParams : public DocumentFormattingParams
            {
              public:
                DocumentOnTypeFormattingParams( const Data& data );

                DocumentOnTypeFormattingParams(
                    const TextDocumentIdentifier& textDocument,
                    const FormattingOptions& options,
                    const Position& position,
                    const std::string& character );

                Position position( void ) const;

                std::string character( void ) const;

                static void validate( const Data& data );
            };

            class DocumentOnTypeFormattingRegistrationOptions
            : public TextDocumentRegistrationOptions
            {
              public:
                DocumentOnTypeFormattingRegistrationOptions( const Data& data );

                DocumentOnTypeFormattingRegistrationOptions(
                    const DocumentSelector& documentSelector,
                    const std::string& firstTriggerCharacter );

                std::string firstTriggerCharacter( void ) const;

                u1 hasMoreTriggerCharacter( void ) const;

                void addMoreTriggerCharacter( const std::string& character );

                std::vector< std::string > moreTriggerCharacter( void ) const;

                static void validate( const Data& data );
            };

            using DocumentOnTypeFormattingResult = DocumentFormattingResult;

            using DocumentRangeFormattingResult = DocumentFormattingResult;

            class RenameParams : public Data
            {
              public:
                RenameParams( const Data& data );

                RenameParams(
                    const TextDocumentIdentifier& textDocument,
                    const Position& position,
                    const std::string& newName );

                TextDocumentIdentifier textDocument( void ) const;

                Position position( void ) const;

                std::string newName( void ) const;

                static void validate( const Data& data );
            };

            class RenameRegistrationOptions : public TextDocumentRegistrationOptions
            {
              public:
                RenameRegistrationOptions( const Data& data );

                RenameRegistrationOptions( const DocumentSelector& selector );

                u1 hasPrepareProvider( void ) const;

                void setPrepareProvider( const u1 prepareProvider );

                u1 prepareProvider( void ) const;

                static void validate( const Data& data );
            };

            class RenameResult : public Data
            {
              public:
                RenameResult( void );

                RenameResult( const Data& data );

                RenameResult( const WorkspaceEdit& edit );

                static void validate( const Data& data );
            };

            using PrepareRenameParams = TextDocumentPositionParams;

            class PrepareRenameResult : public Data
            {
              public:
                PrepareRenameResult( void );

                PrepareRenameResult( const Data& data );

                PrepareRenameResult( const Range& range, const std::string& placeholder );

                static void validate( const Data& data );
            };

            class FoldingRangeParams : public Data
            {
              public:
                FoldingRangeParams( const Data& data );

                FoldingRangeParams( const TextDocumentIdentifier& textDocument );

                TextDocumentIdentifier textDocument( void ) const;

                static void validate( const Data& data );
            };

            enum class FoldingRangeKind
            {
                Comment,
                Imports,
                Region
            };

            class FoldingRange : public Data
            {
              public:
                FoldingRange( const Data& data );

                FoldingRange( const std::size_t startLine, const std::size_t endLine );

                std::size_t startLine( void ) const;

                std::size_t endLine( void ) const;

                u1 hasStartCharacter( void ) const;

                void setStartCharacter( const std::size_t startCharacter );

                std::size_t startCharacter( void ) const;

                u1 hasEndCharacter( void ) const;

                void setEndCharacter( const std::size_t endCharacter );

                std::size_t endCharacter( void ) const;

                u1 hasKind( void ) const;

                void setKind( const FoldingRangeKind kind );

                std::string kind( void ) const;

                static void validate( const Data& data );
            };

            using FoldingRanges = std::vector< FoldingRange >;

            class FoldingRangeResult : public Data
            {
              public:
                FoldingRangeResult( const Data& data );

                FoldingRangeResult( const FoldingRanges& ranges );

                FoldingRangeResult( void );

                static void validate( const Data& data );
            };

            class ExecuteCommandParams : public Data
            {
              public:
                ExecuteCommandParams( const Data& data );

                ExecuteCommandParams( const std::string& command );

                std::string command( void ) const;

                u1 hasArguments( void ) const;

                Data arguments( void ) const;

                void addArgument( const Data& argument );

                static void validate( const Data& data );
            };

            using ExecuteCommandResult = Data;  // TODO: FIXME: @ppaulweber
        }
    }
}

#endif  // _LIBSTDHL_CPP_NETWORK_LSP_CONTENT_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//
