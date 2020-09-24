package org.liblangserver.tests;

import java.util.concurrent.CompletableFuture;

import org.eclipse.lsp4j.InitializeParams;
import org.eclipse.lsp4j.InitializeResult;
import org.eclipse.lsp4j.MessageActionItem;
import org.eclipse.lsp4j.MessageParams;
import org.eclipse.lsp4j.PublishDiagnosticsParams;
import org.eclipse.lsp4j.ShowMessageRequestParams;
import org.eclipse.lsp4j.jsonrpc.Launcher;
import org.eclipse.lsp4j.launch.LSPLauncher;
import org.eclipse.lsp4j.services.LanguageClient;
import org.eclipse.lsp4j.services.LanguageServer;
import org.eclipse.lsp4j.services.TextDocumentService;
import org.eclipse.lsp4j.services.WorkspaceService;

public class Test {
	
	static class MyClient implements LanguageClient {

		@Override
		public void telemetryEvent(Object object) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public void publishDiagnostics(PublishDiagnosticsParams diagnostics) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public void showMessage(MessageParams messageParams) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public CompletableFuture<MessageActionItem> showMessageRequest(ShowMessageRequestParams requestParams) {
			System.out.println("showMessageRequest");
			return null;
		}

		@Override
		public void logMessage(MessageParams message) {
			System.out.println("logMessage");
		}
		
	}
	
	static class MyServer implements LanguageServer {

		@Override
		public CompletableFuture<InitializeResult> initialize(InitializeParams params) {
			// TODO Auto-generated method stub
			return null;
		}

		@Override
		public CompletableFuture<Object> shutdown() {
			// TODO Auto-generated method stub
			return null;
		}

		@Override
		public void exit() {
			// TODO Auto-generated method stub
			
		}

		@Override
		public TextDocumentService getTextDocumentService() {
			System.out.println("getTextDocumentService");
			// TODO Auto-generated method stub
			return null;
		}

		@Override
		public WorkspaceService getWorkspaceService() {
			// TODO Auto-generated method stub
			return null;
		}
	}
	
	public static final void main(String args[]) {
		MyServer server = new MyServer();
		MyClient client = new MyClient();
		
		Launcher<LanguageServer> client_l = LSPLauncher.createClientLauncher(
				client, 
				System.in, 
				System.out);

		InitializeParams params = new InitializeParams();
		client_l.getRemoteProxy().initialize(params);
		client_l.getRemoteProxy().initialize(params);
		client_l.getRemoteProxy().getTextDocumentService();
		client_l.startListening();
		
	}

}
